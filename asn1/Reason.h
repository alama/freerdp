/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "MCS-PROTOCOL-3"
 * 	found in "mcs.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names -gen-PER`
 */

#ifndef	_Reason_H_
#define	_Reason_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum Reason_PR {
	Reason_PR_NOTHING,	/* No components present */
	Reason_PR_rn_domain_disconnected,
	Reason_PR_rn_provider_initiated,
	Reason_PR_rn_token_purged,
	Reason_PR_rn_user_requested,
	Reason_PR_rn_channel_purged,
	/* Extensions may appear below */
	
} Reason_PR;

/* Reason */
typedef struct Reason {
	Reason_PR present;
	union Reason_u {
		NULL_t	 rn_domain_disconnected;
		NULL_t	 rn_provider_initiated;
		NULL_t	 rn_token_purged;
		NULL_t	 rn_user_requested;
		NULL_t	 rn_channel_purged;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} Reason_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Reason;

#ifdef __cplusplus
}
#endif

#endif	/* _Reason_H_ */
