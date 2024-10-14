#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>

struct coord {
    int x;
    int y;
};

struct coord stack[15];
int top = 0;

void push(int x, int y) {
    stack[top].x = x;
    stack[top].y = y;
    top++;
}

struct coord pop() {
    top--;
    return stack[top];
}

float slope(int x1, int x2, int y1, int y2) {
    int yd = y2 - y1;
    int xd = x2 - x1;
    return (float)yd / xd;
}

int orientation(struct coord p, struct coord q, struct coord r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;     // collinear
    return (val > 0) ? 1 : 2;   // clockwise or counterclockwise
}

int compare(const void *vp1, const void *vp2) {
    struct coord *p1 = (struct coord *)vp1;
    struct coord *p2 = (struct coord *)vp2;

    int o = orientation(stack[0], *p1, *p2);
    if (o == 0)
	return (sqrt((p2->x - stack[0].x) * (p2->x - stack[0].x) + (p2->y - stack[0].y) * (p2->y - stack[0].y)) >= sqrt((p1->x - stack[0].x) * (p1->x - stack[0].x) + (p1->y - stack[0].y) * (p1->y - stack[0].y))) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void main(void) {
    int gdriver, gmode;
    struct coord points[7] = {
    {0,0},{100,0},{200,100},
    {200,200},{100,200},{0,100},
    {100,100}
    };
    int n, ymin, min, i, m, h;
    struct coord temp, p0;

    gdriver = DETECT;
    gmode = 0;

    n = 7;
    ymin = points[0].y;
    min = 0;

    initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
    cleardevice();

    for(i = 0; i<7 ; i++)
	putpixel(points[i].x, points[i].y, YELLOW);

    for (i = 1; i < n; i++) {
	int y = points[i].y;
	if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) {
	    ymin = points[i].y;
	    min = i;
	}
    }

    temp = points[0];
    points[0] = points[min];
    points[min] = temp;

    p0 = points[0];
    qsort(&points[1], n-1, sizeof(struct coord), compare);

    m = 1;
    for (i = 1; i < n; i++) {
	while (i < n-1 && orientation(p0, points[i], points[i+1]) == 0)
	    i++;
	points[m] = points[i];
	m++;
    }

    if (m < 3) return;

    push(points[0].x, points[0].y);
    push(points[1].x, points[1].y);
    push(points[2].x, points[2].y);

    for (i = 3; i < m; i++) {
	while (orientation(stack[top-2], stack[top-1], points[i]) != 2)
	    pop();
	push(points[i].x, points[i].y);
    }

    for (i = 0; i < top-1; i++) {
	line(stack[i].x, stack[i].y, stack[i+1].x, stack[i+1].y);
	getch();
    }
    line(stack[top-1].x, stack[top-1].y, stack[0].x, stack[0].y);
    getch();

    closegraph();
}
