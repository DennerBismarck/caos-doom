
class Course:

    def __init__(self):
        self.id: int = None
        self.name: str = None
        self.code: str = None
        self.projects: list[int] = None
        self.materials: list[int] = None
        self.syllabus: list[str] = None
        self.gitHubPage: str = None
