/*
 * QEMU Crypto block IV generator
 *
 * Copyright (c) 2015 Red Hat, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef QCRYPTO_IVGEN_PRIV_H__
#define QCRYPTO_IVGEN_PRIV_H__

#include "crypto/ivgen.h"

typedef struct QCryptoIVGenDriver QCryptoIVGenDriver;

struct QCryptoIVGenDriver {
    int (*init)(QCryptoIVGen *biv,
                QCryptoCipherAlgorithm cipheralg,
                QCryptoHashAlgorithm hash,
                const uint8_t *key, size_t nkey,
                Error **errp);
    int (*calculate)(QCryptoIVGen *biv,
                     uint64_t sector,
                     uint8_t *iv, size_t niv,
                     Error **errp);
    void (*cleanup)(QCryptoIVGen *biv);
};

struct QCryptoIVGen {
    QCryptoIVGenDriver *driver;
    void *private;
};


#endif /* QCRYPTO_IVGEN_PRIV_H__ */
