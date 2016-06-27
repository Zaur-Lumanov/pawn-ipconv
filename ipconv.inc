/* IP Converter
 *
 * Developer: Zaur_Lumanov (https://github.com/Zaur-Lumanov)
 * Repository: https://github.com/Zaur-Lumanov/pawn-ipconv
 *
 * This file is provided as is (no warranties).
 */

#if !defined _ipconv_included
    #define _ipconv_included
#else
    #endinput
#endif

#define IP:: ip_

// native ip_int_to_string(ip);
stock ip_int_to_string(ip) {
    static bytes[4 char], retn[16]; static const ump = 0xFF;
    static const template[] = "%d.%d.%d.%d";
    bytes{0} = ip & ump;
    bytes{1} = (ip >> 8) & ump;
    bytes{2} = (ip >> 16) & ump;
    bytes{3} = (ip >> 24) & ump;	
    format(retn, sizeof(retn), template, bytes{3}, bytes{2}, bytes{1}, bytes{0});
    return retn;
}

// native ip_string_to_int(const ip[]);
stock ip_string_to_int(const ip[]) {
    new result[4], i, index, intip[4 char];
    for(new itt; itt < 4; itt++) {
        if (index != 0 && ip[index]) index++;
        while (ip[index] && ip[index] != 0x2E)
            result[i++] = ip[index++];
        i = 0;
        intip{itt} = strval(result);
    }
    return (intip{0}<<24) | (intip{1}<<16) | (intip{2}<<8) | (intip{3});
}
