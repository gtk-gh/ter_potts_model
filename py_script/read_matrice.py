def read(txt):    f = open(txt, "r")    lines = f.readlines()    i = 0    lin = 0    col = 0    listtemp = []    for line in lines:        if i == 0:            lin = int(line)        elif i == 1:            col = int(line)            templ = [0 for i in range(col)]            for tempi in range(lin):                listtemp.append(templ.copy())        else:            temp = line.split(" ")            for j in range(col-1):                 listtemp[i-2][j] = float(temp[j])            listtemp[i-2][col-1] = float(temp[col-1][:-1])        i += 1    f.close()    return listtemp