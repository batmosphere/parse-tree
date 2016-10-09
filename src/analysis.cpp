MAXIMUM MEMORY USAGE: 3204 KB
RUNNING TIME: LESS THAN 0.001 SECONDS(unmeasurable by CPU clock)

mukund@kothari:~/Desktop/parse-tree/$ time --verbose dist/parsetree "~(((~(t+t))*f)+(t+f)+t)" 12345
Infix String: ~(((~(t+t))*f)+(t+f)+t)
Prefix String: ~+*~+ttf++tft
New Infix String: t+t~*f+t+f+t~
Tree Height: 6
Truth Value: 0
	Command being timed: "/parse-tree/dist/parsetree ~(((~(t+t))*f)+(t+f)+t) 12345"
	User time (seconds): 0.00
	System time (seconds): 0.00
	Percent of CPU this job got: 0%
	Elapsed (wall clock) time (h:mm:ss or m:ss): 0:00.00
	Average shared text size (kbytes): 0
	Average unshared data size (kbytes): 0
	Average stack size (kbytes): 0
	Average total size (kbytes): 0
	Maximum resident set size (kbytes): 3204
	Average resident set size (kbytes): 0
	Major (requiring I/O) page faults: 0
	Minor (reclaiming a frame) page faults: 132
	Voluntary context switches: 1
	Involuntary context switches: 1
	Swaps: 0
	File system inputs: 0
	File system outputs: 0
	Socket messages sent: 0
	Socket messages received: 0
	Signals delivered: 0
	Page size (bytes): 4096
	Exit status: 0
mukund@kothari:~/Desktop/parse-tree/$