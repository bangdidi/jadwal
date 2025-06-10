MainWindow
   |
   v (trigger)
AlgorithmSetupDialog
   | emits configurationReady(algorithm, config)
   v
MainWindow::onConfigurationReady()
   |
   v
AlgorithmProgressDialog
   | receives progress, logs; emits cancelRequested()
   v
GeneticAlgorithm worker (or other algorithm)
   | emits progressChanged(int), logMessage(QString), finished(bool)
   v
AlgorithmProgressDialog (slot onFinished())
   |
   v (signal finishedStatus)
AlgorithmResultDialog (show results, buttons: Reschedule, Show, Export)
