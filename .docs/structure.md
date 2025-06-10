.
├── include
│   ├── core
│   │   ├── Scheduler.h
│   │   ├── DataManager.h
│   │   ├── ConfigManager.h
│   │   └── ApplicationManager.h
│   ├── algorithms
│   │   ├── GeneticAlgorithm.h
│   │   ├── ConstraintPropagationAlgorithm.h
│   │   └── BacktrackingAlgorithm.h
│   ├── data
│   │   ├── entities
│   │   │   ├── Subject.h
│   │   │   ├── Teacher.h
│   │   │   ├── Classroom.h
│   │   │   ├── Timeslot.h
│   │   │   ├── Preferred.h
│   │   │   ├── Unavailable.h
│   │   │   └── Schedule.h
│   │   ├── repositories
│   │   │   ├── SubjectRepository.h
│   │   │   ├── TeacherRepository.h
│   │   │   ├── ClassroomRepository.h
│   │   │   ├── TimeslotRepository.h
│   │   │   ├── PreferredRepository.h
│   │   │   ├── UnavailableRepository.h
│   │   │   └── ScheduleRepository.h
│   │   └── dtos
│   │       ├── SubjectDTO.h
│   │       ├── TeacherDTO.h
│   │       ├── ClassroomDTO.h
│   │       ├── TimeslotDTO.h
│   │       ├── PreferredDTO.h
│   │       ├── UnavailableDTO.h
│   │       └── ScheduleDTO.h
│   ├── io
│   │   ├── reader
│   │   │   ├── XMLReader.h
│   │   │   └── XMLXReader.h
│   │   └── writer
│   │       ├── XMLWriter.h
│   │       └── XMLXWriter.h
│   ├── ui
│   │   ├── subject
│   │   │   ├── SubjectPage.h
│   │   │   └── SubjectDialog.h
│   │   ├── teacher
│   │   │   ├── TeacherPage.h
│   │   │   └── TeacherDialog.h
│   │   ├── classroom
│   │   │   ├── ClassroomPage.h
│   │   │   └── ClassroomDialog.h
│   │   ├── timeslot
│   │   │   ├── TimeslotPage.h
│   │   │   └── TimeslotDialog.h
│   │   ├── preferred
│   │   │   ├── PreferredPage.h
│   │   │   └── PreferredDialog.h
│   │   ├── unavailable
│   │   │   ├── UnavailablePage.h
│   │   │   └── UnavailableDialog.h
│   │   ├── schedule
│   │   │   ├── GenerateDialog.h
│   │   │   └── ProcessPage.h
│   │   ├── MainWindow.h
│   │   └── AboutDialog.h
│   └── utils
│       ├── LanguageUtil.h
│       ├── FileUtil.h
│       ├── TimeUtil.h
│       └── StringUtil.h
│
├── src
│   ├── core
│   │   ├── Scheduler.cpp
│   │   ├── DataManager.cpp
│   │   ├── ConfigManager.cpp
│   │   └── ApplicationManager.cpp
│   ├── algorithms
│   │   ├── GeneticAlgorithm.cpp
│   │   ├── ConstraintPropagationAlgorithm.cpp
│   │   └── BacktrackingAlgorithm.cpp
│   ├── data
│   │   ├── repositories
│   │   │   ├── SubjectRepository.cpp
│   │   │   ├── TeacherRepository.cpp
│   │   │   ├── ClassroomRepository.cpp
│   │   │   ├── TimeslotRepository.cpp
│   │   │   ├── PreferredRepository.cpp
│   │   │   ├── UnavailableRepository.cpp
│   │   │   └── ScheduleRepository.cpp
│   │   └── dtos
│   │       ├── SubjectDTO.cpp
│   │       ├── TeacherDTO.cpp
│   │       ├── ClassroomDTO.cpp
│   │       ├── TimeslotDTO.cpp
│   │       ├── PreferredDTO.cpp
│   │       ├── UnavailableDTO.cpp
│   │       └── ScheduleDTO.cpp
│   ├── io
│   │   ├── reader
│   │   │   ├── XMLReader.cpp
│   │   │   └── XMLXReader.cpp
│   │   └── writer
│   │       ├── XMLWriter.cpp
│   │       └── XMLXWriter.cpp
│   ├── ui
│   │   ├── subject
│   │   │   ├── SubjectPage.cpp
│   │   │   └── SubjectDialog.cpp
│   │   ├── teacher
│   │   │   ├── TeacherPage.cpp
│   │   │   └── TeacherDialog.cpp
│   │   ├── classroom
│   │   │   ├── ClassroomPage.cpp
│   │   │   └── ClassroomDialog.cpp
│   │   ├── timeslot
│   │   │   ├── TimeslotPage.cpp
│   │   │   └── TimeslotDialog.cpp
│   │   ├── preferred
│   │   │   ├── PreferredPage.cpp
│   │   │   └── PreferredDialog.cpp
│   │   ├── unavailable
│   │   │   ├── UnavailablePage.cpp
│   │   │   └── UnavailableDialog.cpp
│   │   ├── schedule
│   │   │   ├── GenerateDialog.cpp
│   │   │   └── ProcessPage.cpp
│   │   ├── MainWindow.cpp
│   │   └── AboutDialog.cpp
│   └── utils
│       ├── LanguageUtil.cpp
│       ├── FileUtil.cpp
│       ├── TimeUtil.cpp
│       └── StringUtil.cpp
│
├── resources
│   └── ui
│       ├── subject
│       │   ├── SubjectPage.ui
│       │   └── SubjectDialog.ui
│       ├── teacher
│       │   ├── TeacherPage.ui
│       │   └── TeacherDialog.ui
│       ├── classroom
│       │   ├── ClassroomPage.ui
│       │   └── ClassroomDialog.ui
│       ├── timeslot
│       │   ├── TimeslotPage.ui
│       │   └── TimeslotDialog.ui
│       ├── preferred
│       │   ├── PreferredPage.ui
│       │   └── PreferredDialog.ui
│       ├── unavailable
│       │   ├── UnavailablePage.ui
│       │   └── UnavailableDialog.ui
│       ├── schedule
│       │   ├── GenerateDialog.ui
│       │   └── ProcessPage.ui
│       ├── MainWindow.ui
│       └── AboutDialog.ui
│
├── LICENSE
├── README.md
├── CMakeLists.txt
├── main.cpp
└── config.ini
