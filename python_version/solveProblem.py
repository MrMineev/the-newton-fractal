from assets import assets

tools = assets()

left_border = -5
right_border = 5
top_border = 5
bottom_border = -5

roundnumber = 1
step = 1

width = 800
height = 800

center_x = width // 2
center_y = height // 2

times_change = 10

minimum_dist = 0.5

dubl = []
print(1)
for i in range(- int(center_x / step), int(center_x / step)):
    for g in range(- int(center_y / step), int(center_y / step)):
        #print(f'i => {i}, g => {g}')
        dubl.append([i * step, g * step])
print(2)
answer = [] # [0] * int(width / step)
for i in range(int(height / step)):
    answer.append([0] * int(width / step))
print(3)
for RealValue in range(int(left_border / step), int(right_border / step)):
    for ImagValue in range(int(bottom_border / step), int(top_border / step)):
        print(f'RealValue => {RealValue}, ImagValue => {ImagValue}')
        tools.Lamda = complex(RealValue, ImagValue)

        points = []
        for i in range(- int(center_x / step), int(center_x / step)):
            for g in range(- int(center_y / step), int(center_y / step)):
                points.append([i * step, g * step])
        for time in range(times_change):
            for point in points:
                real_point = complex(point[0], point[1])
                new_point = real_point - tools.f(real_point) / tools.complex_derivative_f(real_point)
                point = [new_point.real, new_point.imag]
        
        AveragePoint = tools.Lamda / 3
        AveragePoint = complex(round(AveragePoint.real, roundnumber), round(AveragePoint.imag, roundnumber))

        dist = 1e18

        pos = 0

        for point in dubl:
            if complex(point[0], point[1]) == AveragePoint:
                dist1 = tools.magnitude(1 - points[pos])
                dist2 = tools.magnitude(-1 - points[pos])
                dist3 = tools.magnitude(tools.Lamda - points[pos])
                
                dist = 1e18
                index = -1

                if dist1 < dist:
                    dist = dist1
                    index = 0
                if dist2 < dist:
                    dist = dist2
                    index = 1
                if dist3 < dist:
                    dist = dist3
                    index = 2

                if dist > minimum_dist:
                    answer[int(tools.Lamda.real / step)][int(tools.Lamda.imag / step)] = (0, 0, 0)
                else:
                    answer[int(tools.Lamda.real / step)][int(tools.Lamda.imag / step)] = tools.colors[index]

            pos += 1

with open('result.txt') as file:
    for i in range(len(answer)):
        for g in range(len(answer[i])):
            file.write(str(answer[i][g]) + ' ')
        file.write('\n')
    file.close()
        