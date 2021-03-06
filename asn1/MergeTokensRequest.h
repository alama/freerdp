/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "MCS-PROTOCOL-3"
 * 	found in "mcs.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names -gen-PER`
 */

#ifndef	_MergeTokensRequest_H_
#define	_MergeTokensRequest_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SET_OF.h>
#include <constr_SET_OF.h>
#include "TokenId.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct TokenAttributes;
struct NonStandardParameter;

/* MergeTokensRequest */
typedef struct MergeTokensRequest {
	struct MergeTokensRequest__mergeTokens {
		A_SET_OF(struct TokenAttributes) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} mergeTokens;
	struct MergeTokensRequest__purgeTokenIds {
		A_SET_OF(TokenId_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} purgeTokenIds;
	struct MergeTokensRequest__nonStandard {
		A_SEQUENCE_OF(struct NonStandardParameter) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *nonStandard;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MergeTokensRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MergeTokensRequest;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "TokenAttributes.h"
#include "NonStandardParameter.h"

#endif	/* _MergeTokensRequest_H_ */
