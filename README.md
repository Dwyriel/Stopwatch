# Stopwatch
A very simple stopwatch.

### Overhead
Has a very small overhead, which will vary based on many variables (like hardware, OS, other programs, etc.) but should be small and consistent enough to not matter, if you're on a slower computer or want the most precise result as possible, simply call ```Stopwatch::calculateOverhead()``` before using any of the other library's functions and the calculated overhead will be automatically subtracted from the elapsed time. (Because of runtime variation, the result still won't be 100% accurate, but will be closer to it.) 
