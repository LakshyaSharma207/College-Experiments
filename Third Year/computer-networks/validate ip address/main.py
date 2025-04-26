class IPAddress:
    def __init__(self, ip_address):
        self.ip_address = ip_address

    def validate_ip(self):
        octets = self.ip_address.split('.')
        if len(octets) != 4:
            return False
        for octet in octets:
            try:
                if not (0 <= int(octet) <= 255):
                    return False
            except ValueError:
                return False
        return True

    def classify_ip(self):
        first_octet = int(self.ip_address.split('.')[0])
        if 1 <= first_octet <= 126:
            return 'Class A'
        elif 128 <= first_octet <= 191:
            return 'Class B'
        elif 192 <= first_octet <= 223:
            return 'Class C'
        else:
            return 'Unknown'

    def decimal_to_binary(self):
        binary_ip = ''
        octets = self.ip_address.split('.')
        for octet in octets:
            binary_ip += format(int(octet), '08b') + '.'
        return binary_ip[:-1]

    def binary_to_decimal(self, binary_ip):
        decimal_ip = ''
        octets = binary_ip.split('.')
        for octet in octets:
            decimal_ip += str(int(octet, 2)) + '.'
        return decimal_ip[:-1]


# Main code
ip_address = input("Enter an IP address: ")

ip = IPAddress(ip_address)

if ip.validate_ip():
    print(f"IP Address: {ip.ip_address} is valid.")
    print("IP Address class:", ip.classify_ip())
    print("Binary Representation:", ip.decimal_to_binary())
    print("Decimal Representation:", ip.binary_to_decimal(ip.decimal_to_binary()))
else:
    print(f"IP Address: {ip.ip_address} is invalid.")
