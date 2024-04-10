from utils import FILEPath

class Project:

    def __init__(self):
        self.id: int = None
        self.name: str = None
        self.description: str = None
        self.courses: list[int] = None
        self.students: list[int] = None
        self.advisors: list[int] = None
        self.objectives: list[str] = None
        self.documentation: FILEPath = None