# Part 1: Memory reference
#
# this script is able to run on teach.cs
# First you need to make sure proper "ref" files are in /u/csc369h/summer/pub/a3/traces/ folder
# you can directly run "python3 analysis.py" to see the print output or
# use "python3 analysis.py > analysis.txt" to see the result in a file (here it's analysis.txt)
#

if __name__ == "__main__":
    path = "/u/csc369h/summer/pub/a3/traces/addr-"
    traces = ["blocked.ref", "matmul.ref", "repeatloop.ref", "simpleloop.ref"]
    for i in traces:
        curr_path = path + i
        print("Current: ", curr_path)
        ins_num = 0
        data_num = 0
        store = 0
        load = 0
        modify = 0
        instruction = 0
        Instructions = dict()
        Data = dict()

        with open(curr_path, "r") as curr_file:
            lines = curr_file.readlines()

            address = ""

            for j in lines:
                j = j.strip()

                if j[0] == "S":
                    store += 1
                    address = j.split(" ")[1][:-2]
                    address = address[:-3] + "000"
                    if address in Data.keys():
                        Data[address] += 1
                    else:
                        data_num += 1
                        Data[address] = 1

                elif j[0] == "L":
                    load += 1
                    address = j.split(" ")[1][:-2]
                    address = address[:-3] + "000"
                    if address in Data.keys():
                        Data[address] += 1
                    else:
                        data_num += 1
                        Data[address] = 1

                elif j[0] == "M":
                    modify += 1
                    address = j.split(" ")[1][:-2]
                    address = address[:-3] + "000"
                    if address in Data.keys():
                        Data[address] += 1
                    else:
                        data_num += 1
                        Data[address] = 1

                elif j[0] == "I":
                    instruction += 1
                    address = j.split("  ")[1][:-2]
                    address = address[:-3] + "000"
                    if address in Instructions.keys():
                        Instructions[address] += 1
                    else:
                        ins_num += 1
                        Instructions[address] = 1
        print("The number of instruction pages (I): ", ins_num)
        print("The number of data pages (S, L, M): ", data_num)
        print("Count: ")
        print("  Instructions ", instruction)
        print("  Loads        ", load)
        print("  Stores       ", store)
        print("  Modifies     ", modify)
        print("Instructions: ")
        for k in Instructions:
            print("{},{}".format(k, Instructions[k]))
        print("Data: ")
        for k in Data:
            print("{},{}".format(k, Data[k]))
        print("\n\n")
