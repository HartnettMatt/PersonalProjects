// Export to PDF (Typst):
//   typst compile resume.typ
// Typst compiles directly to resume.pdf in the current directory.

#set page(margin: 1in)
#set text(leading: 1.2em)
#show link: set text(fill: blue)

#let section(title) = [
  #block[
    #text(0.95em)[#title]
    #line(length: 100%)
  ]
]

#align(left)[
  #text(size: 20pt, weight: "bold")[Matt Hartnett]
]

*Email:* link("mailto:matthew.e.hartnett@gmail.com")[matthew.e.hartnett@gmail.com]  \\
*GitHub:* link("https://github.com/hartnettmatt")[github.com/hartnettmatt]  \\
*LinkedIn:* link("https://www.linkedin.com/in/hartnettmatt")[linkedin.com/in/hartnettmatt]

#v(8pt)

== Skills

- *Digital Design:* SystemVerilog RTL, Vivado, DSP, tcl, VHDL, Quartus, Libero
- *Digital Verification:* SystemVerilog TB, Cocotb, Verilator, xsim, Modelsim
- *Circuit Design and Analysis:* LTSpice, Advanced Design System, Soldering, Solidworks Electrical, DipTrace, Eagle
- *Software Development:* Python, C++, Embedded C, Java
- *Linux Development:* Ubuntu, Fedora, Buildroot, Yocto, PetaLinux
- *Embedded Programming:* Embedded C, Codasip, Arduino, Raspberry Pi
- *Web Development:* HTML, CSS, Javascript, PHP, SQL
- *Software Systems:* Git, CI/CD, Matlab, Simulink Real-time, OpenCV, SVN
- *General:* Debugging and problem solving for all architectures listed above
- *Project Management Tools:* Agile PLM, Confluence, DOORS NG, OpenText MBPM

== Experience

*Embedded Systems Engineer — FIRST RF*  _Boulder • 10/2024–Present_

- Architected and implemented the full FPGA/HDL stack for a production radar system, owning design from module-level RTL to system integration (SystemVerilog, Vivado).
- Delivered a new DSP pipeline that increased usable bandwidth 4×, improved SNR by ~20 dB, reduced logic utilization, and lowered end-to-end latency; modeled algorithms in Python/NumPy and verified with exhaustive testbenches.
- Engineered a cycle-accurate, latency-constrained data path to meet strict radar timeline requirements; performed both simulation-based and on-hardware validation in partnership with embedded/software teams.
- Modernized the internal HDL build system, enabling Verilator + cocotb flows; authored FIRST RF’s first cocotb testbenches and led full team adoption.

*Electrical Engineer II — Laboratory for Atmospheric and Space Physics*  _CU Boulder • 06/2022–10/2024_

- Designed high reliability test equipment for the *Libera* scientific mission.
- Built systems from the ground up, including hardware, firmware, and software.
- Operated with minimal oversight as the cognizant engineer for multiple projects.

*Electrical Engineering Intern — Laboratory for Atmospheric and Space Physics*  _CU Boulder • 01/2021–06/2022_

- Wrote low-level, hardware interface flight software for the *SPRITE* cubesat mission.
- Developed an FPGA solution to test the scientific instrument on the ground.
- Wrote an image compression algorithm that reduced the scientific data to 1/10th.

*Teaching Assistant — Circuits 1 for Engineers*  _CU Boulder • 08/2021–12/2021_

- Provided support to students in lab and in office hours.
- Graded lab reports and created answer keys.
- Developed midterm questions and helped course organization.

*IT Technician — Leeds School of Business*  _CU Boulder • 01/2020–01/2021_

- Installed and configured hardware and software for workstations and classrooms.
- Communicated technical information through emails and phone calls.

*Robotics Research Assistant — Advanced Robotics Perception Group*  _CU Boulder • 09/2019–05/2020_

- Worked with a large team building a complex navigation robot.
- Used OpenCV for object detection and identification, specifically heat signatures of human dummies, phones, and vents with >80% accuracy.

== Education

- *MSEE, Embedded Systems Engineering (In Progress)* — University of Colorado Boulder  _08/2023–Present • Boulder, Colorado_
- *BS, Electrical and Computer Engineering* — University of Colorado Boulder  _08/2019–05/2022 • Boulder, Colorado_

== Projects

- *Skyler Phased Array RADAR* — Designed the end-to-end DSP chain and datapath (filtering, decimation/interpolation, mixing, 1 Gb/s Ethernet framing), then implemented cycle-accurate RTL with thorough TB coverage. Built a layered verification strategy (SystemVerilog TB + cocotb on Verilator) to catch interface, timing, and algorithmic defects early; mirrored tests on hardware for parity. Drove cross-functional integration and bring-up with embedded and application software, closing timing on high utilization designs, while meeting radar timeline constraints.
- *Libera SSIM* — Led the design of an advanced, high reliability test fixture utilized to validate the performance of the Libera instrument. Created a test rack to simulate the JPSS-3 spacecraft with 100% of interfaces accurately recreated to maximize “Test as you fly” ideology. High reliability system that included a precisely synchronized FPGA with less than 10 ns of timing error.
- *Libera EL Lifetest* — Prepared and implemented the test bed for a 5-year-long, pre-flight motor verification test. Required a custom PCB as well as several custom harnesses to integrate dozens of components into a cohesive system.
- *Senior Design Capstone (FRANKLIN)* — Team lead for a phase-coherent remote sensing system; primarily developed FPGA-based data collection and storage.
- *GSE Detector Readout* — Utilized an FPGA to read data from the scientific detector at full speed and then write that data over 100 Mb/s Ethernet to a PC for a live readout. Implemented a MicroBlaze processor on a Spartan-7 FPGA to run the TCP stack in C.
- *3D Drone Mapping Simulation* — Utilized the Webots simulation software to autonomously map in 3D; a drone sought out unmapped areas using a rapidly-exploring random tree.
- *5‑Stage RISC‑V Processor* — A fully functional and validated processor, built in Codasip using C++ and adapted into RTL as a synthesizable core with IO management, access to off-chip RAM, and 100% verification; designed from the ground up to include the full ISA as well as ECC memory.

== References

- *Dominic Doty* — Software Development Engineer, Amazon — doty.dominic@gmail.com — (303) 704‑8313
- *Jack Williams, PhD* — Senior Electrical Engineer, Blue Canyon Technologies — (303) 735‑8727
