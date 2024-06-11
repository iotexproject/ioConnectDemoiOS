#ifndef PSA_CRYPTO_INVASIVE_H
#define PSA_CRYPTO_INVASIVE_H

#include "include/common.h"
#include "include/iotex/build_info.h"
#include "include/iotex/entropy.h"
#include "include/server/crypto.h"


#if !defined(IOTEX_PSA_CRYPTO_EXTERNAL_RNG)
/** \brief Configure entropy sources.
 *
 * This function may only be called before a call to psa_crypto_init(),
 * or after a call to iotex_psa_crypto_free() and before any
 * subsequent call to psa_crypto_init().
 *
 * This function is only intended for test purposes. The functionality
 * it provides is also useful for system integrators, but
 * system integrators should configure entropy drivers instead of
 * breaking through to the Mbed TLS API.
 *
 * \param entropy_init  Function to initialize the entropy context
 *                      and set up the desired entropy sources.
 *                      It is called by psa_crypto_init().
 *                      By default this is iotex_entropy_init().
 *                      This function cannot report failures directly.
 *                      To indicate a failure, set the entropy context
 *                      to a state where iotex_entropy_func() will
 *                      return an error.
 * \param entropy_free  Function to free the entropy context
 *                      and associated resources.
 *                      It is called by iotex_psa_crypto_free().
 *                      By default this is iotex_entropy_free().
 *
 * \retval #PSA_SUCCESS
 *         Success.
 * \retval #PSA_ERROR_NOT_PERMITTED
 *         The caller does not have the permission to configure
 *         entropy sources.
 * \retval #PSA_ERROR_BAD_STATE
 *         The library has already been initialized.
 */
psa_status_t iotex_psa_crypto_configure_entropy_sources(
    void (* entropy_init )( iotex_entropy_context *ctx ),
    void (* entropy_free )( iotex_entropy_context *ctx ) );
#endif /* !defined(IOTEX_PSA_CRYPTO_EXTERNAL_RNG) */

#if defined(IOTEX_TEST_HOOKS) && defined(IOTEX_PSA_CRYPTO_C)
psa_status_t psa_mac_key_can_do(
    psa_algorithm_t algorithm,
    psa_key_type_t key_type );
#endif /* IOTEX_TEST_HOOKS && IOTEX_PSA_CRYPTO_C */

#endif /* PSA_CRYPTO_INVASIVE_H */
