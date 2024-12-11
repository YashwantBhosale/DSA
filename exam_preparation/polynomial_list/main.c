#include "poly.h"

int main() {
    polynomial p1, p2, p3, p4;
    init_p(&p1);
    append(&p1, 3, 0);
    append(&p1, 1, 2);
    append(&p1, 2, 1);
    display(p1);

    init_p(&p2);
    append(&p2, 5, 0);
    append(&p2, 3, 2);
    append(&p2, 4, 1);
    display(p2);

    p3 = add(p1, p2);
    display(p3);

    p4 = sub(p2, p1);
    display(p4);
    return 0;
}
