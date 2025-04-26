class LeakyBucket:
    def __init__(self, bucket_size, leak_rate):
        self.bucket_size = bucket_size
        self.leak_rate = leak_rate
        self.current_water = 0

    def add_water(self, water_amount):
        potential_water = self.current_water + water_amount
        if potential_water > self.bucket_size:
            print("Bucket overflowed. Only adding", self.bucket_size - self.current_water)
            self.current_water = self.bucket_size
        else:
            self.current_water += water_amount
            print("Added", water_amount, "units of water. Current water", self.current_water)

    def leak_water(self):
        self.current_water -= self.leak_rate
        if self.current_water < 0:
            self.current_water = 0
        print("Leaked", self.leak_rate, "units of water. Current water", self.current_water)


# Initialize a leaky bucket
bucket = LeakyBucket(bucket_size=10, leak_rate=2)

# Add water to the bucket
bucket.add_water(5)
bucket.add_water(6)

# Leak water from the bucket
bucket.leak_water()
