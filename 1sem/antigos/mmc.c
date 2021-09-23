#include <stdio.h>
int main()
{
    int inputs[3];
    scanf("%d %d %d",&inputs[0],&inputs[1],&inputs[2]);
    int cousin[8] = {2, 3, 5, 7, 11, 13, 17, 23};
    int flagRepeatCousin = 0,flagMultiplyMmc=0,flagMultiplyMdc=0, mmc = 1, mdc =1;

    for (int i = 0; i < 8; i++)    {
        if(flagRepeatCousin == 1) {
            i--;
            flagRepeatCousin =0;
        }
        for (int j = 0; j < 3; j++)        {
            if (inputs[j] % cousin[i] == 0){
                inputs[j] = inputs[j] / cousin[i];
                flagMultiplyMmc =1;
                flagMultiplyMdc++;
            }
        }
        if(flagMultiplyMmc == 1) {
            mmc *= cousin[i];
            flagMultiplyMmc =0;
        }

        if(flagMultiplyMdc==3) {
            mdc *= cousin[i];
        }
        flagMultiplyMdc=0;
        for (int j = 0; j < 3; j++)        {
            if (inputs[j] % cousin[i] == 0)            {
                flagRepeatCousin = 1;
            }
        }
    }
    printf("%d %d", mmc, mdc);
    return 0;
}
