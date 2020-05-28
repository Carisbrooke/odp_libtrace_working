#ifndef FORMAT_LINUX_XDP
#define FORMAT_LINUX_XDP

/* Exit return codes */
#define EXIT_OK              0 /* == EXIT_SUCCESS (stdlib.h) man exit(3) */
#define EXIT_FAIL            1 /* == EXIT_FAILURE (stdlib.h) man exit(3) */
#define EXIT_FAIL_OPTION     2
#define EXIT_FAIL_XDP       30
#define EXIT_FAIL_BPF       40

/* replace path with autoconf varible?? */
static char libtrace_xdp_kern[] = "/usr/local/share/libtrace/format_linux_xdp_kern.bpf";
static char libtrace_xdp_prog[] = "libtrace_xdp";

typedef struct libtrace_xdp {
    /* BPF filter */
    __u64 received_packets;
    __u64 accepted_packets;
    __u64 filtered_packets;
    __u64 dropped_packets;
} libtrace_xdp_t;

typedef enum {
    XDP_BALANCE = 0,
    XDP_UNIDIRECTIONAL = 1,
    XDP_BIDIRECTIONAL = 2,
} xdp_hasher;

typedef struct libtrace_ctrl_map {
    xdp_hasher hasher;
    int max_queues;
} libtrace_ctrl_map_t;

#endif
