# General Notes

A subnet mask describes which portion of an IP address is the network address, with the remainder being the host address.
It is applied to the IP address with a bitwise AND.

For example, with the IPv4 address 192.0.2.12, the first three bytes could be the network and the last byte could be the host. In other words, we could be addressing host 12 on network 192.0.2.0, described by the network mask 255.255.255.0.
