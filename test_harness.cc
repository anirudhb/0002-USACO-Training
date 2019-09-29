/**
 * Test harness for other files.
 *
 * Usage:
 * First argument is the executable to test. Tries exe then exe.exe.
 * Then exe is called as such:
 * exe
 * This exe should read from exe.in and output to exe.out.
 * If exe.out is not the same as exe.expected,
 * a diff will be created and printed to STDERR.
 * The program will exit with an error.
 */