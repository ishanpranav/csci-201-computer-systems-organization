#include <stdlib.h>
#include "tlb_entry.h"

struct TlbEntry
{
    int tag;
    int index;
    int physicalPageNumber;
};

TlbEntry tlb_entry(int tag, int index, int physicalPageNumber)
{
    TlbEntry result = malloc(sizeof result);

    result->tag = tag;
    result->index = index;
    result->physicalPageNumber = physicalPageNumber;

    return result;
}
