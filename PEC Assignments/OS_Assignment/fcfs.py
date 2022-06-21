from collections import deque
import numpy as np
import matplotlib.pyplot as plt 
from distinctipy import distinctipy
def unique_color(n):
# Get n distinct color
    return distinctipy.get_colors(n)
def prepare_ready_queue(processes: list)-> list:
    ready_queue = deque()
    for process in processes:
        ready_queue.appendleft(process)
    return ready_queue
def start_plotting(intervals: list, process_cnt: int, processor_cnt: int, 
p: list, time_slice: int)->None:
# p-> process_names as well as keeps track of whether that element is 
visited before or not
col = unique_color(process_cnt)
plt.title(f"CPU Schedule \nNumber of cores: {process_cnt}\nTime_Slice: 
{time_slice}")
xmax = 0
for i in range(len(intervals)):
for process in intervals[i]:
cur_col = col[process[0]]
# To keep only distinct legends 
if (not p[process[0]][1]):
plt.plot([process[1], process[2]], [i, i], '-o', color =
cur_col, label = p[process[0]][0])
p[process[0]][1] = True
else:
plt.plot([process[1], process[2]], [i, i], '-o', color =
cur_col)
xmax = max(xmax, process[2])
process_names = [f"Processor {i + 1}" for i in range(processor_cnt)]
plt.margins(y = 1, tight = False)
plt.xticks(np.arange(0, xmax + 5, 2))
plt.yticks(np.arange(0, processor_cnt, 1), process_names)
plt.grid(axis = 'x', color = 'black', linestyle = '--', linewidth =
'0.4')
plt.legend()
plt.show()
def get_timimg_diagram_data(n: int, processes: list, time_slice: int, 
p_cnt: int)-> list:
# Use appendleft and pop to use deque as queue
ready_queue = prepare_ready_queue(processes)
# Keep track of time for each processor
timer = [0 for i in range(p_cnt)]
# Keep the intervals in following manner for each processor: 
# processor-i -> (Process-Name, start, end)
intervals = [[] for i in range(p_cnt)]
# Take out top-(p_cnt) items decrease burst time and then if they are 
still non-zero remove it
while(len(ready_queue) != 0):
usable_process = min(len(ready_queue), p_cnt)
for i in range(usable_process):
# i denote which processor we are taking into account
current_process = ready_queue.pop()
process_id = current_process[2]
process_time = current_process[1] 
# Add process name and start time (end time will be added 
later)
current_interval = [process_id] 
current_interval.append(timer[i])
current_process[1] = max(0, process_time - time_slice)
timer[i] += min(process_time, time_slice)
# If the process is still not finished push it back into queue
if (current_process[1] > 0):
ready_queue.appendleft(current_process)
current_interval.append(timer[i])
# Add current interval data
intervals[i].append(current_interval)
return intervals 
def average(arr: list):
if len(arr):
return sum(arr)/len(arr)
return 0
def auxillary_details(intervals: list, p_cnt: int, arrival_time: list, 
processes: list)-> None:
completion_time = [0 for i in range(p_cnt)]
turn_around_time = [-1 for i in range(p_cnt)]
waiting_time = [-1 for i in range(p_cnt)]
for processor in intervals:
for jobs in processor:
completion_time[jobs[0]] = max(completion_time[jobs[0]], 
jobs[2])
turn_around_time = [completion_time[i] - arrival_time[i] for i in
range(p_cnt)]
waiting_time = [turn_around_time[i] - processes[i][1] for i in
range(p_cnt)]
print(f"Turn Around Time: {turn_around_time}")
print(f"Average Turn Around Time: {average(turn_around_time)}")
print(f"Waiting Around Time: {waiting_time}")
print(f"Average Waiting Time: {average(waiting_time)}")
if __name__ == "__main__":
n = int(input())
processes = []
process_name = []
for i in range(n):
process_time = input().split() # Keeps process name and time
process_time[1] = int(process_time[1]) 
process_time.append(i) # Keeps Process id
processes.append(process_time)
process_name.append([process_time[0], False])
# Arrival Time
arrival_time = [int(x) for x in input().split()]
time_slice = int(input())
processor_cnt = int(input())
intervals = get_timimg_diagram_data(n, processes, time_slice, 
processor_cnt)
auxillary_details(intervals, n, arrival_time, processes)
start_plotting(intervals, n, processor_cnt, process_name, time_slice)
