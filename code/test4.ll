; ModuleID = 'hello'
source_filename = "hello"

@0 = private unnamed_addr constant [2 x i8] c"\0A\00"
@f = internal global i32 zeroinitializer, align 4
@k = internal global i32 zeroinitializer, align 4
@fk = internal global i32 zeroinitializer, align 4
@t = internal global double zeroinitializer, align 4
@1 = private unnamed_addr constant [4 x i8] c"%d \00"
@2 = private unnamed_addr constant [4 x i8] c"%d \00"

define void @main() {
entry:
  store i32 0, i32* @k
  %callproc = call i32 @go(i32* @k, i32 5)
  store i32 %callproc, i32* @f
  %0 = load i32, i32* @f
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %0)
  %2 = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0))
  %3 = load i32, i32* @k
  %4 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @2, i32 0, i32 0), i32 %3)
  %5 = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @go(i32* %b, i32 %a) {
entry:
  %go = alloca i32
  %b1 = alloca i32*
  store i32* %b, i32** %b1
  %a2 = alloca i32
  store i32 %a, i32* %a2
  %0 = load i32, i32* %a2
  %cmptmp = icmp ugt i32 %0, 0
  br i1 %cmptmp, label %then, label %else

then:                                             ; preds = %entry
  %1 = load i32, i32* %a2
  %2 = load i32*, i32** %b1
  %3 = load i32, i32* %a2
  %subtmp = sub i32 %3, 1
  %callproc = call i32 @go(i32* %2, i32 %subtmp)
  %multmp = mul i32 %1, %callproc
  store i32 %multmp, i32* %go
  br label %ifcont

else:                                             ; preds = %entry
  store i32 1, i32* %go
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %4 = load i32*, i32** %b1
  %5 = load i32*, i32** %b1
  %6 = load i32, i32* %5
  %7 = load i32, i32* %go
  %addtmp = add i32 %6, %7
  store i32 %addtmp, i32* %4
  %8 = load i32, i32* @k
  %9 = load i32, i32* %go
  %addtmp3 = add i32 %8, %9
  store i32 %addtmp3, i32* @k
  %10 = load i32, i32* %go
  ret i32 %10
}
