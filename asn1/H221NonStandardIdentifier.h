/*
 * Generated by asn1c-0.9.22.1409 (http://lionet.info/asn1c)
 * From ASN.1 module "MCS-PROTOCOL-3"
 * 	found in "mcs.asn1"
 * 	`asn1c -fnative-types -fskeletons-copy -fcompound-names -gen-PER`
 */

#ifndef	_H221NonStandardIdentifier_H_
#define	_H221NonStandardIdentifier_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* H221NonStandardIdentifier */
typedef OCTET_STRING_t	 H221NonStandardIdentifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_H221NonStandardIdentifier;
asn_struct_free_f H221NonStandardIdentifier_free;
asn_struct_print_f H221NonStandardIdentifier_print;
asn_constr_check_f H221NonStandardIdentifier_constraint;
ber_type_decoder_f H221NonStandardIdentifier_decode_ber;
der_type_encoder_f H221NonStandardIdentifier_encode_der;
xer_type_decoder_f H221NonStandardIdentifier_decode_xer;
xer_type_encoder_f H221NonStandardIdentifier_encode_xer;
per_type_decoder_f H221NonStandardIdentifier_decode_uper;
per_type_encoder_f H221NonStandardIdentifier_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _H221NonStandardIdentifier_H_ */
