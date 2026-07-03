#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void slide_left(int *line, size_t size)
{
    size_t i, insert_pos = 0;

    /* Step 1: Slide all non-zero elements to the left */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (i != insert_pos)
            {
                line[insert_pos] = line[i];
                line[i] = 0;
            }
            insert_pos++;
        }
    }

    /* Step 2: Merge identical adjacent elements */
    for (i = 0; i < size - 1; i++)
    {
        if (line[i] != 0 && line[i] == line[i + 1])
        {
            line[i] *= 2;
            line[i + 1] = 0;
        }
    }

    /* Step 3: Slide all non-zero elements to the left again */
    insert_pos = 0;
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            if (i != insert_pos)
            {
                line[insert_pos] = line[i];
                line[i] = 0;
            }
            insert_pos++;
        }
    }
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 */
void slide_right(int *line, size_t size)
{
    size_t i, insert_pos;

    if (size == 0)
        return;

    /* Step 1: Slide all non-zero elements to the right */
    insert_pos = size - 1;
    for (i = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            if (i - 1 != insert_pos)
            {
                line[insert_pos] = line[i - 1];
                line[i - 1] = 0;
            }
            if (insert_pos > 0)
                insert_pos--;
        }
    }

    /* Step 2: Merge identical adjacent elements */
    for (i = size; i > 1; i--)
    {
        if (line[i - 1] != 0 && line[i - 1] == line[i - 2])
        {
            line[i - 1] *= 2;
            line[i - 2] = 0;
        }
    }

    /* Step 3: Slide all non-zero elements to the right again */
    insert_pos = size - 1;
    for (i = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            if (i - 1 != insert_pos)
            {
                line[insert_pos] = line[i - 1];
                line[i - 1] = 0;
            }
            if (insert_pos > 0)
                insert_pos--;
        }
    }
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
        slide_left(line, size);
    else
        slide_right(line, size);

    return (1);
}
