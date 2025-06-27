class StatisticsCalculator:
    def __init__(self, data):
        self.data = sorted(data)

# function to calculate mean
    def mean(self):
        return sum(self.data) / len(self.data)
    
# function to calculate median
    def median(self):
        n = len(self.data)
        mid = n // 2
        if n % 2 == 0:
            return (self.data[mid - 1] + self.data[mid]) / 2
        else:
            return self.data[mid]
        
#function to calculate mode
    def mode(self):
        frequency = {}
        for num in self.data:
            frequency[num] = frequency.get(num, 0) + 1
        max_freq = max(frequency.values())
        return [k for k, v in frequency.items() if v == max_freq]
    
# Example usage
if __name__ == '__main__':
    numbers = [2, 6, 11, 1, 18, 2, 4]
    calc = StatisticsCalculator(numbers)
    print("Mean:", calc.mean())
    print("Median:", calc.median())
    print("Mode:", calc.mode())
