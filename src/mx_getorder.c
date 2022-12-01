#include "header.h"

int *mx_getorder(int **graph, char **difIslands, int index) {
    int size = mx_getsize_arr(difIslands);
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (graph[index][i] != 0)
        {
            count++;
        }
    }
    
    int length = count;
    int *order = (int*)malloc(sizeof(int) * (count + 1));
    int **valueIndex = (int**)malloc(sizeof(int*) * (count + 1));
    order[count] = 0;
    valueIndex[count] = NULL;

    for (int i = 0; i < count; i++)
    {
        valueIndex[i] = (int*)malloc(sizeof(int) * 2);
    }
    
    count = 0;

    for (int i = 0; i < size; i++)
    {
        if (graph[index][i] != 0)
        {
            valueIndex[count][0] = graph[index][i];
            valueIndex[count][1] = i + 1;
            count++;
        }
    }

    bool rule = true;

	while (rule)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (valueIndex[i][0] > valueIndex[i + 1][0])
			{
				int tempValue = valueIndex[i][0];
                int tempIndex = valueIndex[i][1];

				valueIndex[i][0] = valueIndex[i + 1][0];
                valueIndex[i][1] = valueIndex[i + 1][1];
				valueIndex[i + 1][0] = tempValue;
                valueIndex[i + 1][1] = tempIndex;
				rule = false;
			}
		}
		if (!rule)
		{
			rule = true;
		}
		else break;
	}

    for (int i = 0; i < length; i++)
    {
        order[i] = valueIndex[i][1];
    }

    return order;
}
