/**
 * @file      FASTA.h
 * @brief     Compression/Decompression of FASTA
 * @author    Morteza Hosseini  (seyedmorteza@ua.pt)
 * @author    Diogo Pratas      (pratas@ua.pt)
 * @author    Armando J. Pinho  (ap@ua.pt)
 * @copyright The GNU General Public License v3.0
 */

#ifndef CRYFA_FASTA_H
#define CRYFA_FASTA_H

#include "EnDecrypto.h"


/** @brief Packing FASTA */
struct packfa_s
{
    /** @brief Points to a header packing function */
    void (EnDecrypto::*packHdrFPtr) (string&, const string&, const htbl_t&);
};

/** @brief Unpakcing FASTA */
struct unpackfa_s
{
    char  XChar_hdr;           /**< @brief Extra char if header's length > 39 */
    pos_t begPos;              /**< @brief Begining position for each thread */
    u64   chunkSize;           /**< @brief Chunk size */
    vector<string> hdrUnpack;  /**< @brief Lookup table for unpacking headers */
    /** @brief Points to a header unpacking function */
    void (EnDecrypto::*unpackHdrFPtr)
         (string&, string::iterator&, const vector<string>&);
};


class FASTA : public EnDecrypto
{
public:
    FASTA             () = default;
    void compressFA   ();
//    void decompressFA ();

//private:
    void gatherHdrBs      (string&);
    void packFA           (const packfa_s&,   byte);
//    inline void unpackHS         (const unpackfa_s&, byte);
//    inline void unpackHL         (const unpackfa_s&, byte);
//    inline void unpackSeqFA_3to1 (string&, string::iterator&);
};


#endif //CRYFA_FASTA_H