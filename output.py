import os

if __name__ == "__main__":
    m = [50, 100]
    path = "./sim -f /u/csc369h/summer/pub/a3/traces/page-"
    ref = ["repeatloop", "simpleloop", "matmul", "blocked"]
    replacement = ["fifo", "clock", "lru", "mru"]
    for i in ref:
        for j in m:
            for k in replacement:
                curr = path + i + ".ref -m " + str(j) + " -s 5000 -a " + k + " >./output/" + i + str(j) + k + ".txt"
                os.system(curr)
