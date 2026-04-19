#include <stdio.h>

int main()
{
    int n, i, j;
    int items[50];
    int bin_capacity;
    int bin_rem[50];
    int bins_used = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter sizes of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &bin_capacity);

    for(i = 0; i < n; i++)
    {
        int placed = 0;
        for(j = 0; j < bins_used; j++)
        {
            if(bin_rem[j] >= items[i])
            {
                bin_rem[j] -= items[i];
                placed = 1;
                break;
            }
        }
        if(!placed)
        {
            bin_rem[bins_used] = bin_capacity - items[i];
            bins_used++;
        }
    }

    printf("\nRemaining space in bins:\n");
    for(i = 0; i < bins_used; i++)
    {
        printf("Bin %d: %d\n", i + 1, bin_rem[i]);
    }

    return 0;
}
