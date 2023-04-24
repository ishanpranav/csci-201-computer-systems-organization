/**
 * TlbEntry
*/
struct TlbEntry;

/**
 * TlbEntry
*/
typedef struct TlbEntry* TlbEntry;

/**
 * tlb_entry
 * @param tag tag
 * @param index index
 * @param physicalPageNumber physical page number
 * @return TlbEntry
*/
TlbEntry tlb_entry(int tag, int index, int physicalPageNumber);
