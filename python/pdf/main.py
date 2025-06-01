from fpdf import FPDF

# Create PDF document
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)
pdf.add_page()
pdf.set_font("Arial", style='B', size=16)
pdf.cell(200, 10, "Weekly Study Routine", ln=True, align='C')
pdf.ln(10)

# Set normal font for body text
pdf.set_font("Arial", size=12)

# Weekly Schedule Content
schedule_content = [
    ("Monday (Holiday)", [
        "6:00 AM - 6:30 AM: Bath & Freshen Up",
        "6:30 AM - 8:30 AM: Mock Interviews & Communication Practice",
        "8:45 AM - 9:20 AM: Breakfast",
        "9:30 AM - 12:30 PM: Python Backend with AI (Ollama, FastAPI, AI Integration)",
        "12:30 PM - 2:30 PM: Advanced DSA (Graphs, DP, Trees, etc.)",
        "2:30 PM - 4:00 PM: Full-Stack Development (React, Next.js, Node.js, Fastify, Express)",
        "4:00 PM - 5:30 PM: Break & Fun Activities",
        "5:30 PM - 7:00 PM: Database Optimization & Query Writing (MySQL, PostgreSQL, MongoDB)",
        "7:00 PM - 8:45 PM: Job Preparation & Resume Building",
        "9:00 PM - 10:00 PM: Dinner",
        "10:00 PM - 11:30 PM: Personal Projects & Open Source Contributions",
        "11:30 PM - 12:00 AM: Relax & Wind Down"
    ]),
    ("Tuesday - Saturday (College Days)", [
        "6:00 AM - 6:30 AM: Bath & Freshen Up",
        "6:30 AM - 8:30 AM: Communication Practice & Job Preparation",
        "8:45 AM - 9:20 AM: Breakfast",
        "9:30 AM - 12:30 PM: College (Non-Conflict Time)",
        "12:30 PM - 2:00 PM: Full-Stack Development (React, Next.js, Node.js, Fastify, Express)",
        "2:00 PM - 4:00 PM: Computer Networking & Control System",
        "4:00 PM - 5:00 PM: Break & Relax",
        "5:00 PM - 6:30 PM: DSA & Java Backend (JDBC, Spring Boot, etc.)",
        "6:30 PM - 7:30 PM: Gym/Exercise/Walk",
        "7:30 PM - 8:45 PM: Android Development (Expo)",
        "9:00 PM - 10:00 PM: Dinner",
        "10:00 PM - 11:30 PM: SQL & Database Practice (PostgreSQL, MySQL, MongoDB)",
        "11:30 PM - 12:00 AM: Relax & Wind Down"
    ]),
    ("Sunday (Holiday)", [
        "6:00 AM - 6:30 AM: Bath & Freshen Up",
        "6:30 AM - 8:30 AM: Mock Interviews & Resume Building",
        "8:45 AM - 9:20 AM: Breakfast",
        "9:30 AM - 12:30 PM: CMOS VLSI & Economics Study",
        "12:30 PM - 2:30 PM: Backend System Design (Java & Python)",
        "2:30 PM - 4:00 PM: Advanced Java Backend & DSA Practice",
        "4:00 PM - 6:00 PM: Full-Stack Project Contributions",
        "6:00 PM - 7:30 PM: Networking & Security Concepts",
        "7:30 PM - 8:45 PM: Python Backend with AI (Ollama, FastAPI, AI Integration)",
        "9:00 PM - 10:00 PM: Dinner",
        "10:00 PM - 11:30 PM: Job Preparation & Weekly Recap",
        "11:30 PM - 12:00 AM: Relax & Sleep Preparation"
    ])
]

# Add schedule content to PDF
for day, tasks in schedule_content:
    pdf.set_font("Arial", style='B', size=14)
    pdf.cell(0, 8, day, ln=True)
    pdf.ln(2)
    pdf.set_font("Arial", size=12)
    for task in tasks:
        pdf.cell(0, 7, "- " + task, ln=True)
    pdf.ln(5)

# Save PDF file in a valid Windows directory
pdf_filename = "F:/dsa/python/pdf/weekly_study_routine.pdf"  # Change to your directory
pdf.output(pdf_filename)

print(f"PDF generated successfully at: {pdf_filename}")
