#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double get_area(triangle tr)
{
    double p = (tr.a + tr.b + tr.c) / 2.0;
    return sqrt(p * (p - tr.a) * (p - tr.b) * (p - tr.c));
}
void sort_by_area(triangle* tr, int n) {
    double *area = malloc(n*sizeof(double));
    int i;
    for(i=0;i<n;i++)
    {
        area[i] = get_area(tr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (area[j] > area[j + 1]) {
                double temp_area = area[j];
                area[j] = area[j + 1];
                area[j + 1] = temp_area;
                triangle temp_triangle = tr[j];
                tr[j] = tr[j + 1];
                tr[j + 1] = temp_triangle;
            }
        }
    }

}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}