/*
    SSSD

    Kerberos Backend, private header file

    Authors:
        Sumit Bose <sbose@redhat.com>

    Copyright (C) 2009 Red Hat


    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __KRB5_AUTH_H__
#define __KRB5_AUTH_H__

#define MAX_CHILD_MSG_SIZE 255
#define CCACHE_ENV_NAME "KRB5CCNAME"
#define SSSD_KRB5_CHANGEPW_PRINCIPLE "SSSD_KRB5_CHANGEPW_PRINCIPLE"

typedef enum { INIT_PW, INIT_KT, RENEW, VALIDATE } action_type;

struct krb5_ctx {
    /* opts taken from kinit */
    /* in seconds */
    krb5_deltat starttime;
    krb5_deltat lifetime;
    krb5_deltat rlife;

    int forwardable;
    int proxiable;
    int addresses;

    int not_forwardable;
    int not_proxiable;
    int no_addresses;

    int verbose;

    char* principal_name;
    char* service_name;
    char* keytab_name;
    char* k5_cache_name;
    char* k4_cache_name;

    action_type action;

    int num_pa_opts;
    krb5_gic_opt_pa_data *pa_opts;

    char *kdcip;
    char *realm;
    bool try_simple_upn;
    char *changepw_principle;
};

#endif /* __KRB5_AUTH_H__ */
