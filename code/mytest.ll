; ModuleID = 'hello'
source_filename = "hello"

@i = internal global double zeroinitializer, align 4
@0 = private unnamed_addr constant [4 x i8] c"%f \00"
@1 = private unnamed_addr constant [2 x i8] c"\0A\00"

define void @main() {
entry:
  store double fadd (double 4.500000e+00, i32 3), double* @i
  %0 = load double, double* @i
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @0, i32 0, i32 0), double %0)
  %2 = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @1, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)
