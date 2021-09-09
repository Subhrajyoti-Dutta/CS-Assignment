//Name: Subhrajyoti Dutta
//Roll No: 20220STA066
//Sub: CS-103P

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    //approximate values of 2/3: a) 0.7 b) 0.67 c) 0.66667
    double app[3] = { 0.7, 0.67, 0.66667 };
    double act_val = 2.0 / 3.0, app_val;
    double abs_err, rel_err, per_err;
    for (int i = 0; i < 3; i++) {
        app_val = app[i];
        printf("Approximate value: %lf\n", app_val);
        abs_err = fabs(act_val - app[i]);
        printf("\tAbsolute Error: %lf\n", abs_err);
        rel_err = abs_err / act_val;
        printf("\tRelative Error: %lf\n", rel_err);
        per_err = rel_err * 100;
        printf("\tPercentage Error: %lf\n\n", per_err);
    }
    return 0;
}