from datetime import date
from curriculum import Curriculum

class Teacher:

    def __init__(self):
        self.id: int = None
        self.firstName: str = None
        self.surnames: str = None
        self.birthDate: date = None
        self.institution: str = None
        self.email: str = None
        self.curriculum: Curriculum = None
        self.description: str = None
        self.areasOfInterest: list[str] = None
        self.projects: list[int] = None
        self.publications: list[int] = None
        self.awards: list[str] = None
        self.authorityUsername: str = None
        self.authorityPassword: str = None
