// http://www.spoj.com/problems/ORDERSET/

#include <cstdio>
#include <algorithm>
using namespace std;

enum class Color { RED, BLACK };

struct RBTreeNode {
    int key;
    int size;
    Color color;
    RBTreeNode *parent;
    RBTreeNode *left;
    RBTreeNode *right;
    RBTreeNode() = default;
    RBTreeNode(int k, RBTreeNode *l, RBTreeNode *r) : key(k), size(1), color(Color::RED),
                                                      parent(nullptr), left(l), right(r) { }
};

class RBTree {
private:
    RBTreeNode *Nil;
    RBTreeNode *root_;
    int num_nodes;

    RBTreeNode* GetUncle(RBTreeNode *x);

    int Select(RBTreeNode *x, int k);

    void LeftRotation(RBTreeNode *x);

    void RightRotation(RBTreeNode *x);

    void RBInsertFixup(RBTreeNode *x);

    void RBTransplant(RBTreeNode *u, RBTreeNode *v);

    void RBDelete(RBTreeNode *z);

    void RBDeleteFixup(RBTreeNode *x);

    void Cleanup(RBTreeNode *x);
public:
    RBTree() : num_nodes(0) {
        Nil = new RBTreeNode();
        Nil->size = 0;
        Nil->color = Color::BLACK;
        Nil->left = Nil;
        Nil->right = Nil;
        root_ = Nil;
    }

    ~RBTree() {
        Cleanup(root_);
        delete Nil;
    }

    RBTreeNode* Search(int key);

    int K_th(int k);

    int Count(int key);

    void RBInsert(int key);

    void RBDelete(int key);

    int Size() { return num_nodes; };
};

int RBTree::K_th(int k) {
    return Select(root_, k);
}

int RBTree::Select(RBTreeNode *x, int k) {
    int r = x->left->size + 1;
    if (k == r) {
        return x->key;
    } else if (k < r) {
        return Select(x->left, k);
    } else {
        return Select(x->right, k - r);
    }
}

int RBTree::Count(int key) {
    RBTreeNode *x = root_;
    int count = 0;
    while (x != Nil) {
        if (key == x->key) {
            return count + x->left->size;
        } else if (key < x->key) {
            x = x->left;
        } else {
            count += x->left->size + 1;
            x = x->right;
        }
    }
    return count;
}

RBTreeNode* RBTree::Search(int key) {
    RBTreeNode *x = root_;
    while (x != Nil) {
        if (key == x->key) {
            return x;
        } else if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return nullptr;  // return nullptr if not found
}

RBTreeNode* RBTree::GetUncle(RBTreeNode *x) {
    RBTreeNode* p = x->parent;
    RBTreeNode* g = x->parent->parent;
    return p == g->left ? g->right : g->left;
}

void RBTree::LeftRotation(RBTreeNode *x) {
    RBTreeNode *y = x->right;
    x->right = y->left;
    if (y->left != Nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == Nil) {
        root_ = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
    // maintain size
    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

void RBTree::RightRotation(RBTreeNode *x) {
    RBTreeNode *y = x->left;
    x->left = y->right;
    if (y->right != Nil) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == Nil) {
        root_ = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
    // maintain size
    y->size = x->size;
    x->size = x->left->size + x->right->size + 1;
}

void RBTree::RBInsert(int key) {
    RBTreeNode *y = Nil;
    RBTreeNode *x = root_;
    while (x != Nil) {
        y = x;
        if (key == x->key) {
            return;
        } else if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    num_nodes++;
    RBTreeNode *z = new RBTreeNode(key, Nil, Nil);
    z->parent = y;
    if (y == Nil) {
        root_ = z;
    } else if (key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    while (y != Nil) {
        y->size++;
        y = y->parent;
    }
    RBInsertFixup(z);
}

void RBTree::RBInsertFixup(RBTreeNode *x) {
    while (x != root_ && x->parent->color == Color::RED) { // x is red at the beginning of each iteration
        RBTreeNode* u = GetUncle(x);
        RBTreeNode* p = x->parent;
        RBTreeNode* g = p->parent;   // g can't be NULL since x->parent->color == Color::RED
        if (u->color == Color::RED) { // uncle is red
            u->color = Color::BLACK;
            x = g;
        }
        else if (p == g->left) {
            if (x == p->right) {             // LR case
                LeftRotation(p);
                swap(x, p);
            }
            RightRotation(g);                // LL case
        }
        else {
            if (x == p->left) {              // RL case
                RightRotation(p);
                swap(x, p);
            }
            LeftRotation(g);                 // RR case
        }
        p->color = Color::BLACK;
        g->color = Color::RED;
    }
    root_->color = Color::BLACK;
}

void RBTree::RBTransplant(RBTreeNode *u, RBTreeNode *v) {
    RBTreeNode *p = u->parent;
    if (p == Nil) {
        root_ = v;
    } else if (u == p->left) {
        p->left = v;
    } else {
        p->right = v;
    }
    v->parent = p;
}

void RBTree::RBDelete(int key) {
    RBTreeNode *x = Search(key);
    if (x) {
        num_nodes--;
        RBTreeNode *y = x;
        while (y != Nil) {
            y->size--;
            y = y->parent;
        }
        RBDelete(x);
    }
}

void RBTree::RBDelete(RBTreeNode *z) {
    RBTreeNode *x = Nil;
    RBTreeNode *y = z;
    Color y_original_color = y->color;
    if (z->left == Nil) {
        x = z->right;
        RBTransplant(z, z->right);
    } else if (z->right == Nil) {
        x = z->left;
        RBTransplant(z, z->left);
    }
    else {
        y = z->right;
        while (y->left != Nil) {
            y = y->left;
        }
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            x->parent = y;
        } else {
            RBTransplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
            RBTreeNode *w = x->parent;
            while (w != y) {
                w->size--;
                w = w->parent;
            }
            y->size = y->left->size + 1;
        }
        RBTransplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->size = y->left->size + y->right->size + 1;
        y->color = z->color;
    }

    z->left = Nil;
    z->right = Nil;
    delete z;

    if (y_original_color == Color::BLACK) {
        RBDeleteFixup(x);
    }
}

void RBTree::RBDeleteFixup(RBTreeNode *x) {
    while (x != root_ && x->color == Color::BLACK) {
        RBTreeNode *p = x->parent;
        if (x == p->left) {
            RBTreeNode *w = p->right;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                p->color = Color::RED;
                LeftRotation(p);
                w = p->right;
            }
            if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                w->color = Color::RED;
                x = p;
            }
            else {
                if (w->right->color == Color::BLACK) {
                    w->left->color = Color::BLACK;
                    w->color = Color::RED;
                    RightRotation(w);
                    w = p->right;
                }
                w->color = p->color;
                p->color = Color::BLACK;
                w->right->color = Color::BLACK;
                LeftRotation(p);
                x = root_;
            }
        }
        else {
            RBTreeNode *w = p->left;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                p->color = Color::RED;
                RightRotation(p);
                w = p->left;
            }
            if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                w->color = Color::RED;
                x = p;
            }
            else {
                if (w->left->color == Color::BLACK) {
                    w->right->color = Color::BLACK;
                    w->color = Color::RED;
                    LeftRotation(w);
                    w = p->left;
                }
                w->color = p->color;
                p->color = Color::BLACK;
                w->left->color = Color::BLACK;
                RightRotation(p);
                x = root_;
            }
        }
    }
    x->color = Color::BLACK;
}

void RBTree::Cleanup(RBTreeNode *x) {
    if (x == Nil) {
        return;
    }
    Cleanup(x->left);
    Cleanup(x->right);
    delete x;
}

int main() {
    RBTree rbtree;
    int q;
    scanf("%d ", &q);
    while (q--) {
        char c;
        int a;
        scanf(" %c %d", &c, &a);
        if (c == 'I') {
            rbtree.RBInsert(a);
        } else if (c == 'D') {
            rbtree.RBDelete(a);
        } else if (c == 'K') {
            if (a > rbtree.Size()) {
                printf("invalid\n");
            } else {
                printf("%d\n", rbtree.K_th(a));
            }
        } else {
            printf("%d\n", rbtree.Count(a));
        }
    }
}
