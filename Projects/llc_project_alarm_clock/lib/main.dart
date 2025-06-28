// main.dart
import 'package:flutter/material.dart';
import 'dart:async';
import 'dart:math';
import 'package:intl/intl.dart';

void main() {
  runApp(const MathAlarmApp());
}

class MathAlarmApp extends StatelessWidget {
  const MathAlarmApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Math Alarm Clock',
      theme: ThemeData.dark().copyWith(
        primaryColor: Colors.deepPurple,
        colorScheme: const ColorScheme.dark(
          primary: Colors.deepPurple,
          secondary: Colors.purpleAccent,
        ),
        scaffoldBackgroundColor: Colors.black,
        textTheme: const TextTheme(
          headlineMedium: TextStyle(
            color: Colors.white,
            fontWeight: FontWeight.bold,
          ),
          headlineSmall: TextStyle(color: Colors.white70),
          bodyLarge: TextStyle(color: Colors.white),
        ),
      ),

      home: const HomePage(),
      debugShowCheckedModeBanner: false,
    );
  }
}

class HomePage extends StatefulWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  State<HomePage> createState() => _HomePageState();
}

class _HomePageState extends State<HomePage>
    with SingleTickerProviderStateMixin {
  late TabController _tabController;
  int _currentIndex = 0;

  @override
  void initState() {
    super.initState();
    _tabController = TabController(length: 4, vsync: this);
    _tabController.addListener(() {
      setState(() {
        _currentIndex = _tabController.index;
      });
    });
  }

  @override
  void dispose() {
    _tabController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
          backgroundColor: const Color.fromARGB(255, 34, 4, 56),
          title: const Text("Alarm", style: TextStyle(color : Color.fromARGB(255, 255, 237, 255),),),
          toolbarHeight: 60,
        ),
      body: SafeArea(
        child: TabBarView(
          controller: _tabController,
          physics: const BouncingScrollPhysics(),
          children: const [
            ClockPage(),
            AlarmPage(),
            StopwatchPage(),
            TimerPage(),
          ],
        ),
      ),
      bottomNavigationBar: Container(
        decoration: BoxDecoration(
          color: Colors.black,
          boxShadow: [
            BoxShadow(
              color: Colors.deepPurple.withOpacity(0.3),
              blurRadius: 10,
              offset: const Offset(0, -3),
            ),
          ],
        ),
        child: TabBar(
          controller: _tabController,
          indicatorColor: Colors.purpleAccent,
          labelColor: Colors.purpleAccent,
          unselectedLabelColor: Colors.white54,
          tabs: const [
            Tab(icon: Icon(Icons.access_time), text: "Clock"),
            Tab(icon: Icon(Icons.alarm), text: "Alarm"),
            Tab(icon: Icon(Icons.timer), text: "Stopwatch"),
            Tab(icon: Icon(Icons.hourglass_bottom), text: "Timer"),
          ],
        ),
      ),
    );
  }
}

// Clock Page
class ClockPage extends StatefulWidget {
  const ClockPage({Key? key}) : super(key: key);

  @override
  State<ClockPage> createState() => _ClockPageState();
}

class _ClockPageState extends State<ClockPage>
    with AutomaticKeepAliveClientMixin {
  late Timer _timer;
  DateTime _now = DateTime.now();

  @override
  void initState() {
    super.initState();
    _timer = Timer.periodic(const Duration(milliseconds: 16), (timer) {
      setState(() {
        _now = DateTime.now();
      });
    });
  }

  @override
  void dispose() {
    _timer.cancel();
    super.dispose();
  }

  @override
  bool get wantKeepAlive => true;

  @override
  Widget build(BuildContext context) {
    super.build(context);

    final timeFormat = DateFormat('HH:mm:ss');
    final dateFormat = DateFormat('EEEE, MMMM d, y');

    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 30, vertical: 40),
            decoration: BoxDecoration(
              color: Colors.grey[900],
              borderRadius: BorderRadius.circular(20),
              boxShadow: [
                BoxShadow(
                  color: Colors.deepPurple.withOpacity(0.3),
                  blurRadius: 15,
                  spreadRadius: 5,
                ),
              ],
            ),
            child: Column(
              children: [
                Text(
                  timeFormat.format(_now),
                  style: const TextStyle(
                    color: Color.fromARGB(255, 227, 217, 255),
                    fontSize: 40,
                    fontWeight: FontWeight.bold,
                    fontFamily: 'monospace',
                    letterSpacing: 2,
                  ),
                ),
                const SizedBox(height: 10),
                Text(
                  dateFormat.format(_now),
                  style: const TextStyle(fontSize: 18, color: Colors.white70),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

// Alarm Page
class AlarmPage extends StatefulWidget {
  const AlarmPage({Key? key}) : super(key: key);

  @override
  State<AlarmPage> createState() => _AlarmPageState();
}

class _AlarmPageState extends State<AlarmPage>
    with AutomaticKeepAliveClientMixin {
  List<Alarm> alarms = [];
  Timer? _checkAlarmTimer;

  @override
  void initState() {
    super.initState();
    // Check for active alarms every second
    _checkAlarmTimer = Timer.periodic(const Duration(seconds: 1), (timer) {
      _checkAlarms();
    });
  }

  @override
  void dispose() {
    _checkAlarmTimer?.cancel();
    super.dispose();
  }

  void _checkAlarms() {
    final now = DateTime.now();

    for (var alarm in alarms) {
      if (alarm.isActive && !alarm.isTriggered) {
        final alarmTime = DateTime(
          now.year,
          now.month,
          now.day,
          alarm.time.hour,
          alarm.time.minute,
          0,
        );

        // Check if it's time to trigger the alarm
        if (now.isAfter(alarmTime) && now.difference(alarmTime).inMinutes < 1) {
          setState(() {
            alarm.isTriggered = true;
          });

          // Show the math challenge dialog
          _showMathChallengeDialog(alarm);
        }
      }
    }
  }

  void _showMathChallengeDialog(Alarm alarm) {
    final random = Random();
    int a = random.nextInt(20) + 1;
    int b = random.nextInt(20) + 1;
    int operation = random.nextInt(3); // 0: +, 1: -, 2: *
    String operationSymbol;
    int answer;

    switch (operation) {
      case 0:
        operationSymbol = '+';
        answer = a + b;
        break;
      case 1:
        // Make sure the result is positive
        if (a < b) {
          int temp = a;
          a = b;
          b = temp;
        }
        operationSymbol = '-';
        answer = a - b;
        break;
      case 2:
        operationSymbol = '×';
        answer = a * b;
        break;
      default:
        operationSymbol = '+';
        answer = a + b;
    }

    final TextEditingController answerController = TextEditingController();

    showDialog(
      context: context,
      barrierDismissible: false,
      builder: (context) {
        return AlertDialog(
          backgroundColor: Colors.grey[900],
          title: const Text(
            "Solve to Dismiss Alarm",
            style: TextStyle(color: Colors.purpleAccent),
          ),
          content: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              Text(
                "Solve: $a $operationSymbol $b = ?",
                style: const TextStyle(
                  fontSize: 22,
                  fontWeight: FontWeight.bold,
                ),
              ),
              const SizedBox(height: 20),
              TextField(
                controller: answerController,
                keyboardType: TextInputType.number,
                autofocus: true,
                decoration: InputDecoration(
                  hintText: "Enter answer",
                  border: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(12),
                    borderSide: BorderSide(color: Colors.purpleAccent),
                  ),
                  focusedBorder: OutlineInputBorder(
                    borderRadius: BorderRadius.circular(12),
                    borderSide: BorderSide(
                      color: Colors.purpleAccent,
                      width: 2,
                    ),
                  ),
                ),
              ),
            ],
          ),
          actions: [
            TextButton(
              onPressed: () {
                try {
                  final userAnswer = int.parse(answerController.value.text);
                  if (userAnswer == answer) {
                    // Correct answer, dismiss the alarm
                    setState(() {
                      alarm.isTriggered = false;
                    });
                    Navigator.of(context).pop();
                  } else {
                    // Incorrect answer, show error
                    ScaffoldMessenger.of(context).showSnackBar(
                      const SnackBar(
                        content: Text("Incorrect! Try again."),
                        backgroundColor: Colors.red,
                      ),
                    );
                  }
                } catch (e) {
                  ScaffoldMessenger.of(context).showSnackBar(
                    const SnackBar(
                      content: Text("Please enter a valid number"),
                      backgroundColor: Colors.red,
                    ),
                  );
                }
              },
              child: const Text(
                "Check",
                style: TextStyle(color: Colors.purpleAccent),
              ),
            ),
          ],
        );
      },
    );
  }

  void _addNewAlarm() async {
    final TimeOfDay? picked = await showTimePicker(
      context: context,
      initialTime: TimeOfDay.now(),
      builder: (BuildContext context, Widget? child) {
        return Theme(
          data: ThemeData.dark().copyWith(
            colorScheme: const ColorScheme.dark(
              primary: Colors.purpleAccent,
              onPrimary: Colors.white,
              surface: Colors.grey,
              onSurface: Colors.white,
            ),
            dialogBackgroundColor: Colors.grey[900],
          ),
          child: child!,
        );
      },
    );

    if (picked != null) {
      setState(() {
        alarms.add(Alarm(time: picked));
      });
    }
  }

  @override
  bool get wantKeepAlive => true;

  @override
  Widget build(BuildContext context) {
    super.build(context);

    return Stack(
      children: [
        alarms.isEmpty
            ? const Center(
              child: Text(
                "No alarms set.\nAdd an alarm by tapping the + button.",
                textAlign: TextAlign.center,
                style: TextStyle(color: Colors.white70, fontSize: 16),
              ),
            )
            : ListView.builder(
              padding: const EdgeInsets.only(bottom: 80),
              itemCount: alarms.length,
              itemBuilder: (context, index) {
                final alarm = alarms[index];
                return AlarmTile(
                  alarm: alarm,
                  onToggle: (value) {
                    setState(() {
                      alarm.isActive = value;
                      if (!value) {
                        alarm.isTriggered = false;
                      }
                    });
                  },
                  onDelete: () {
                    setState(() {
                      alarms.removeAt(index);
                    });
                  },
                );
              },
            ),
        Positioned(
          right: 20,
          bottom: 20,
          child: TweenAnimationBuilder(
            tween: Tween<double>(begin: 0, end: 1),
            duration: const Duration(milliseconds: 500),
            builder: (context, double value, child) {
              return Transform.scale(scale: value, child: child);
            },
            child: FloatingActionButton(
              onPressed: _addNewAlarm,
              backgroundColor: Colors.purpleAccent,
              child: const Icon(Icons.add, color: Colors.white),
            ),
          ),
        ),
      ],
    );
  }
}

class AlarmTile extends StatelessWidget {
  final Alarm alarm;
  final Function(bool) onToggle;
  final VoidCallback onDelete;

  const AlarmTile({
    Key? key,
    required this.alarm,
    required this.onToggle,
    required this.onDelete,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return TweenAnimationBuilder<double>(
      tween: Tween<double>(begin: 0, end: 1),
      duration: const Duration(milliseconds: 500),
      builder: (context, value, child) {
        return Transform.translate(
          offset: Offset(0, (1 - value) * 50),
          child: Opacity(opacity: value, child: child),
        );
      },
      child: Card(
        margin: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
        color:
            alarm.isTriggered
                ? Colors.redAccent.withOpacity(0.2)
                : Colors.grey.shade900,
        elevation: 4,
        shape: RoundedRectangleBorder(
          borderRadius: BorderRadius.circular(16),
          side: BorderSide(
            color: alarm.isTriggered ? Colors.redAccent : Colors.transparent,
            width: 2,
          ),
        ),
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 12),
          child: Row(
            children: [
              const SizedBox(width: 8),
              Icon(
                Icons.alarm,
                color: alarm.isActive ? Colors.purpleAccent : Colors.grey,
                size: 28,
              ),
              const SizedBox(width: 16),
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      alarm.time.format(context),
                      style: TextStyle(
                        fontSize: 24,
                        fontWeight: FontWeight.bold,
                        color: alarm.isActive ? Colors.white : Colors.white60,
                      ),
                    ),
                    Text(
                      alarm.isTriggered
                          ? "Active - Solve math problem to dismiss!"
                          : (alarm.isActive ? "Active" : "Inactive"),
                      style: TextStyle(
                        fontSize: 14,
                        color:
                            alarm.isTriggered
                                ? Colors.redAccent
                                : Colors.white60,
                      ),
                    ),
                  ],
                ),
              ),
              Switch(
                value: alarm.isActive,
                onChanged: onToggle,
                activeColor: Colors.purpleAccent,
              ),
              IconButton(
                icon: const Icon(Icons.delete, color: Colors.red),
                onPressed: onDelete,
              ),
            ],
          ),
        ),
      ),
    );
  }
}

class Alarm {
  final TimeOfDay time;
  bool isActive;
  bool isTriggered;

  Alarm({required this.time, this.isActive = true, this.isTriggered = false});
}

// Stopwatch Page
class StopwatchPage extends StatefulWidget {
  const StopwatchPage({Key? key}) : super(key: key);

  @override
  State<StopwatchPage> createState() => _StopwatchPageState();
}

class _StopwatchPageState extends State<StopwatchPage>
    with AutomaticKeepAliveClientMixin {
  Stopwatch _stopwatch = Stopwatch();
  late Timer _timer;
  List<Duration> laps = [];

  @override
  void initState() {
    super.initState();
    _timer = Timer.periodic(const Duration(milliseconds: 8), (timer) {
      setState(() {
        // Update UI at approximately 120 FPS
      });
    });
  }

  @override
  void dispose() {
    _timer.cancel();
    _stopwatch.stop();
    super.dispose();
  }

  void _toggleStopwatch() {
    setState(() {
      if (_stopwatch.isRunning) {
        _stopwatch.stop();
      } else {
        _stopwatch.start();
      }
    });
  }

  void _resetStopwatch() {
    setState(() {
      _stopwatch.stop();
      _stopwatch.reset();
      laps.clear();
    });
  }

  void _recordLap() {
    if (_stopwatch.isRunning) {
      setState(() {
        laps.add(_stopwatch.elapsed);
      });
    }
  }

  String _formatDuration(Duration duration) {
    String twoDigits(int n) => n.toString().padLeft(2, '0');
    String threeDigits(int n) => n.toString().padLeft(3, '0');

    final minutes = twoDigits(duration.inMinutes.remainder(60));
    final seconds = twoDigits(duration.inSeconds.remainder(60));
    final milliseconds = threeDigits(duration.inMilliseconds.remainder(1000));

    return "$minutes:$seconds.$milliseconds";
  }

  @override
  bool get wantKeepAlive => true;

  @override
  Widget build(BuildContext context) {
    super.build(context);

    return Column(
      children: [
        Expanded(
          flex: 4,
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  "Stopwatch",
                  style: Theme.of(context).textTheme.headlineMedium,
                ),
                const SizedBox(height: 20),
                TweenAnimationBuilder<double>(
                  tween: Tween<double>(begin: 0.8, end: 1.0),
                  duration: const Duration(milliseconds: 300),
                  builder: (context, value, child) {
                    return Transform.scale(
                      scale:
                          _stopwatch.isRunning
                              ? (0.95 +
                                  0.05 *
                                      sin(
                                        DateTime.now().millisecondsSinceEpoch /
                                            500,
                                      ))
                              : value,
                      child: child,
                    );
                  },
                  child: Container(
                    padding: const EdgeInsets.all(70),
                    decoration: BoxDecoration(
                      shape: BoxShape.circle,
                      color: Colors.grey[900],
                      boxShadow: [
                        BoxShadow(
                          color: Colors.purpleAccent.withOpacity(0.3),
                          blurRadius: 15,
                          spreadRadius: 8,
                        ),
                      ],
                    ),
                    child: Text(
                      _formatDuration(_stopwatch.elapsed),
                      style: const TextStyle(
                        color: Color.fromARGB(255, 227, 217, 255),
                        fontSize: 36,
                        fontWeight: FontWeight.bold,
                        fontFamily: 'monospace',
                      ),
                    ),
                  ),
                ),
                const SizedBox(height: 30),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    _buildControlButton(
                      icon:
                          _stopwatch.isRunning ? Icons.pause : Icons.play_arrow,
                      color:
                          _stopwatch.isRunning ? Colors.orange : Colors.green,
                      onPressed: _toggleStopwatch,
                    ),
                    const SizedBox(width: 20),
                    _buildControlButton(
                      icon: Icons.refresh,
                      color: Colors.red,
                      onPressed: _resetStopwatch,
                    ),
                    const SizedBox(width: 20),
                    _buildControlButton(
                      icon: Icons.flag,
                      color: Colors.blue,
                      onPressed: _stopwatch.isRunning ? _recordLap : null,
                    ),
                  ],
                ),
              ],
            ),
          ),
        ),
        Expanded(
          flex: 3,
          child:
              laps.isEmpty
                  ? const Center(
                    child: Text(
                      "No laps recorded",
                      style: TextStyle(color: Colors.white70),
                    ),
                  )
                  : Container(
                    margin: const EdgeInsets.all(16),
                    decoration: BoxDecoration(
                      color: Colors.grey[900],
                      borderRadius: BorderRadius.circular(16),
                    ),
                    child: ListView.builder(
                      itemCount: laps.length,
                      itemBuilder: (context, index) {
                        final reversedIndex = laps.length - 1 - index;
                        final lap = laps[reversedIndex];

                        // Calculate lap time difference
                        final previousLap =
                            reversedIndex > 0
                                ? laps[reversedIndex - 1]
                                : Duration.zero;
                        final lapDiff = lap - previousLap;

                        return ListTile(
                          leading: CircleAvatar(
                            backgroundColor: Colors.deepPurple,
                            child: Text(
                              "${reversedIndex + 1}",
                              style: const TextStyle(color: Colors.white),
                            ),
                          ),
                          title: Text(
                            _formatDuration(lap),
                            style: const TextStyle(fontFamily: 'monospace'),
                          ),
                          trailing: Text(
                            reversedIndex > 0
                                ? "+ ${_formatDuration(lapDiff)}"
                                : _formatDuration(lap),
                            style: TextStyle(
                              color: Colors.white70,
                              fontFamily: 'monospace',
                            ),
                          ),
                        );
                      },
                    ),
                  ),
        ),
      ],
    );
  }

  Widget _buildControlButton({
    required IconData icon,
    required Color color,
    required VoidCallback? onPressed,
  }) {
    return ElevatedButton(
      onPressed: onPressed,
      style: ElevatedButton.styleFrom(
        backgroundColor: color.withOpacity(0.2),
        foregroundColor: color,
        shape: const CircleBorder(),
        padding: const EdgeInsets.all(16),
      ),
      child: Icon(icon, size: 30),
    );
  }
}

// Timer Page
class TimerPage extends StatefulWidget {
  const TimerPage({Key? key}) : super(key: key);

  @override
  State<TimerPage> createState() => _TimerPageState();
}

class _TimerPageState extends State<TimerPage>
    with AutomaticKeepAliveClientMixin {
  late Stopwatch _stopwatch;
  late Timer _timer;
  Duration _selectedDuration = const Duration(minutes: 1);
  Duration _remainingTime = Duration.zero;
  bool _isRunning = false;
  bool _isCompleted = false;

  @override
  void initState() {
    super.initState();
    _stopwatch = Stopwatch();
    _remainingTime = _selectedDuration;

    _timer = Timer.periodic(const Duration(milliseconds: 16), (timer) {
      if (_isRunning) {
        setState(() {
          final elapsed = _stopwatch.elapsed;
          if (elapsed >= _selectedDuration) {
            _remainingTime = Duration.zero;
            _isRunning = false;
            _isCompleted = true;
            _stopwatch.stop();
            _showTimerCompleteDialog();
          } else {
            _remainingTime = _selectedDuration - elapsed;
          }
        });
      }
    });
  }

  @override
  void dispose() {
    _timer.cancel();
    _stopwatch.stop();
    super.dispose();
  }

  void _setTimer(Duration duration) {
    setState(() {
      _selectedDuration = duration;
      _resetTimer();
    });
  }

  void _toggleTimer() {
    setState(() {
      if (_isRunning) {
        _stopwatch.stop();
      } else {
        if (_isCompleted) {
          _resetTimer();
        }
        _stopwatch.start();
      }
      _isRunning = !_isRunning;
      _isCompleted = false;
    });
  }

  void _resetTimer() {
    setState(() {
      _stopwatch.stop();
      _stopwatch.reset();
      _isRunning = false;
      _isCompleted = false;
      _remainingTime = _selectedDuration;
    });
  }

  void _showTimerCompleteDialog() {
    showDialog(
      context: context,
      builder:
          (context) => AlertDialog(
            backgroundColor: Colors.grey[900],
            title: const Text(
              "Timer Complete",
              style: TextStyle(color: Colors.purpleAccent),
            ),
            content: const Text("Your timer has finished!",style: TextStyle(color:Color.fromARGB(255, 227, 217, 255),),),
            actions: [
              TextButton(
                onPressed: () {
                  Navigator.of(context).pop();
                },
                child: const Text(
                  "OK",
                  style: TextStyle(color: Colors.purpleAccent),
                ),
              ),
            ],
          ),
    );
  }

  String _formatDuration(Duration duration) {
    String twoDigits(int n) => n.toString().padLeft(2, '0');
    String threeDigits(int n) => n.toString().padLeft(3, '0');

    final hours = twoDigits(duration.inHours);
    final minutes = twoDigits(duration.inMinutes.remainder(60));
    final seconds = twoDigits(duration.inSeconds.remainder(60));
    final milliseconds = threeDigits(duration.inMilliseconds.remainder(1000));

    if (duration.inHours > 0) {
      return "$hours:$minutes:$seconds.$milliseconds";
    } else {
      return "$minutes:$seconds.$milliseconds";
    }
  }

  @override
  bool get wantKeepAlive => true;

  @override
  Widget build(BuildContext context) {
    super.build(context);

    return Column(
      children: [
        Expanded(
          flex: 4,
          child: Center(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Text(
                  "Timer",
                  style: Theme.of(context).textTheme.headlineMedium,
                ),
                const SizedBox(height: 20),
                TweenAnimationBuilder<double>(
                  tween: Tween<double>(begin: 0.8, end: 1.0),
                  duration: const Duration(milliseconds: 300),
                  builder: (context, value, child) {
                    return Transform.scale(
                      scale:
                          _isRunning
                              ? (0.95 +
                                  0.05 *
                                      sin(
                                        DateTime.now().millisecondsSinceEpoch /
                                            500,
                                      ))
                              : value,
                      child: child,
                    );
                  },
                  child: Container(
                    padding: const EdgeInsets.all(70),
                    decoration: BoxDecoration(
                      shape: BoxShape.circle,
                      color: Colors.grey[900],
                      boxShadow: [
                        BoxShadow(
                          color:
                              _isCompleted
                                  ? Colors.redAccent.withOpacity(0.5)
                                  : Colors.purpleAccent.withOpacity(0.3),
                          blurRadius: 15,
                          spreadRadius: 5,
                        ),
                      ],
                    ),
                    child: Text(
                      _formatDuration(_remainingTime),
                      style: TextStyle(
                        fontSize: 36,
                        fontWeight: FontWeight.bold,
                        fontFamily: 'monospace',
                        color: _isCompleted ? Colors.redAccent : const Color.fromARGB(255, 227, 217, 255),
                      ),
                    ),
                  ),
                ),
                const SizedBox(height: 30),
                Row(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    _buildControlButton(
                      icon: _isRunning ? Icons.pause : Icons.play_arrow,
                      color: _isRunning ? Colors.orange : Colors.green,
                      onPressed: _toggleTimer,
                    ),
                    const SizedBox(width: 20),
                    _buildControlButton(
                      icon: Icons.refresh,
                      color: Colors.red,
                      onPressed: _resetTimer,
                    ),
                  ],
                ),
              ],
            ),
          ),
        ),
        Expanded(
          flex: 2,
          child: Container(
            margin: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.grey[900],
              borderRadius: BorderRadius.circular(16),
            ),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                const SizedBox(height: 8),
                const Text(
                  "Preset Timers",
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold,color: Color.fromARGB(255, 227, 217, 255),),
                ),
                const SizedBox(height: 16),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    _buildTimerPresetButton(
                      "1 min",
                      const Duration(minutes: 1),
                    ),
                    _buildTimerPresetButton(
                      "5 min",
                      const Duration(minutes: 5),
                    ),
                    _buildTimerPresetButton(
                      "10 min",
                      const Duration(minutes: 10),
                    ),
                  ],
                ),
                const SizedBox(height: 10),
                Row(
                  mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                  children: [
                    _buildTimerPresetButton(
                      "15 min",
                      const Duration(minutes: 15),
                    ),
                    _buildTimerPresetButton(
                      "30 min",
                      const Duration(minutes: 30),
                    ),
                    _buildTimerPresetButton("1 hour", const Duration(hours: 1)),
                  ],
                ),
                const SizedBox(height: 16),
                OutlinedButton.icon(
                  onPressed: () async {
                    // Custom timer dialog
                    final result = await showDialog<Duration>(
                      context: context,
                      builder: (context) => const CustomTimerDialog(),
                    );

                    if (result != null) {
                      _setTimer(result);
                    }
                  },
                  icon: const Icon(Icons.timer, color: Colors.purpleAccent),
                  style: OutlinedButton.styleFrom(
                    side: const BorderSide(color: Colors.purpleAccent),
                  ),
                  label: const Text(
                    "Custom",
                    style: TextStyle(color: Colors.purpleAccent),
                  ),
                ),
              ],
            ),
          ),
        ),
      ],
    );
  }

  Widget _buildControlButton({
    required IconData icon,
    required Color color,
    required VoidCallback onPressed,
  }) {
    return ElevatedButton(
      onPressed: onPressed,
      style: ElevatedButton.styleFrom(
        backgroundColor: color.withOpacity(0.2),
        foregroundColor: color,
        shape: const CircleBorder(),
        padding: const EdgeInsets.all(16),
      ),
      child: Icon(icon, size: 30),
    );
  }

  Widget _buildTimerPresetButton(String label, Duration duration) {
    final isSelected = !_isRunning && _selectedDuration == duration;

    return ElevatedButton(
      onPressed: _isRunning ? null : () => _setTimer(duration),
      style: ElevatedButton.styleFrom(
        backgroundColor: isSelected ? Colors.purpleAccent : Colors.grey[800],
        foregroundColor: isSelected ? Colors.white : Colors.white70,
        padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
        elevation: isSelected ? 5 : 1,
      ),
      child: Text(label),
    );
  }
}

class CustomTimerDialog extends StatefulWidget {
  const CustomTimerDialog({Key? key}) : super(key: key);

  @override
  State<CustomTimerDialog> createState() => _CustomTimerDialogState();
}

class _CustomTimerDialogState extends State<CustomTimerDialog>
    with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation<double> _animation;

  int hours = 0;
  int minutes = 0;
  int seconds = 0;

  @override
  void initState() {
    super.initState();
    _controller = AnimationController(
      duration: const Duration(milliseconds: 500),
      vsync: this,
    );
    _animation = CurvedAnimation(
      parent: _controller,
      curve: Curves.easeOutBack,
    );
    _controller.forward();
  }

  @override
  void dispose() {
    _controller.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return ScaleTransition(
      scale: _animation,
      child: AlertDialog(
        backgroundColor: Colors.grey[900],
        title: const Text(
          "Set Custom Timer",
          style: TextStyle(color: Colors.purpleAccent),
        ),
        content: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                _buildTimeSelector(
                  label: "Hours",
                  value: hours,
                  onChanged: (value) {
                    setState(() {
                      hours = value;
                    });
                  },
                  maxValue: 23,
                ),
                _buildTimeSelector(
                  label: "Minutes",
                  value: minutes,
                  onChanged: (value) {
                    setState(() {
                      minutes = value;
                    });
                  },
                  maxValue: 59,
                ),
                _buildTimeSelector(
                  label: "Seconds",
                  value: seconds,
                  onChanged: (value) {
                    setState(() {
                      seconds = value;
                    });
                  },
                  maxValue: 59,
                ),
              ],
            ),
          ],
        ),
        actions: [
          TextButton(
            onPressed: () {
              Navigator.pop(context);
            },
            child: const Text(
              "Cancel",
              style: TextStyle(color: Colors.white70),
            ),
          ),
          ElevatedButton(
            onPressed: () {
              final duration = Duration(
                hours: hours,
                minutes: minutes,
                seconds: seconds,
              );
              if (duration.inMilliseconds > 0) {
                Navigator.pop(context, duration);
              } else {
                ScaffoldMessenger.of(context).showSnackBar(
                  const SnackBar(
                    content: Text("Please set a duration greater than zero"),
                    backgroundColor: Colors.red,
                  ),
                );
              }
            },
            style: ElevatedButton.styleFrom(
              backgroundColor: Colors.purpleAccent,
            ),
            child: const Text("Set"),
          ),
        ],
      ),
    );
  }

  Widget _buildTimeSelector({
    required String label,
    required int value,
    required Function(int) onChanged,
    required int maxValue,
  }) {
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        Text(
          label,
          style: const TextStyle(fontSize: 12, color: Colors.white70),
        ),
        const SizedBox(height: 8),
        Container(
          decoration: BoxDecoration(
            color: Colors.black26,
            borderRadius: BorderRadius.circular(12),
          ),
          padding: const EdgeInsets.symmetric(horizontal: 4),
          child: Column(
            children: [
              IconButton(
                icon: const Icon(Icons.arrow_drop_up, color: Colors.white),
                onPressed: () {
                  onChanged((value < maxValue) ? value + 1 : 0);
                },
              ),
              Text(
                value.toString().padLeft(2, '0'),
                style: const TextStyle(
                  fontSize: 24,
                  fontWeight: FontWeight.bold,
                ),
              ),
              IconButton(
                icon: const Icon(Icons.arrow_drop_down, color: Colors.white),
                onPressed: () {
                  onChanged((value > 0) ? value - 1 : maxValue);
                },
              ),
            ],
          ),
        ),
      ],
    );
  }
}

// main.dart complete
