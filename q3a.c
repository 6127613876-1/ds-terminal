#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define t 11
#define r 7

int l[t];

void insert(int x) {
    int i, h, hi, f, h2;
    i = 0;
    h = x % t;
    h2 = r - (x % r);
    f = i * h2;
    hi = (h + f) % t;
    
    if (l[hi] == 0) {
        l[hi] = x;
    }
    else {
        while (l[hi] != 0) {
            i++;
            h2 = r - (x % r);
            f = i * h2;
            hi = (h + f) % t;
        }
        l[hi] = x;
    }
}

void print() {
    int i;
    printf("INDEX\t\tVALUE\n");
    for (i = 0; i < t; i++) {
        printf("%d\t\t%d\n", i, l[i]);
    }
}

int search(int x) {
    int i, h, hi, h2, f;
    h = x % t;
    for (i = 0; i < t; i++) {
        h2 = r - (x % r);
        f = i * h2;
        hi = (h + f) % t;
        if (l[hi] == x) {
            return hi;
        }
    }
    return -1;
}

void index(int target) {
    int sub;
    int i = 0;
    while (i < 11) {
        sub = target - l[i];
        if (sub < 0) {
            sub = abs(sub);
        }
        int foundIndex = search(sub);
        if (foundIndex != -1 && foundIndex != i) {
            printf("[%d %d]\n", i, foundIndex);
            return;
        }
        i++;
    }
    printf("The given target sum is not found.\n");
}

int main() {
    int i, op, c = 1, x;
    int target;

    for (i = 0; i < t; i++) {
        l[i] = 0;
    }

    while (c == 1) {
        printf("1. Insert\nEnter option: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &x);
            insert(x);
            break;
        }
        
        printf("Enter 1 to continue: ");
        scanf("%d", &c);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    print();
    index(target);

    return 0;
}