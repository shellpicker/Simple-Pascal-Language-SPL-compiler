; ModuleID = 'hello'
source_filename = "hello"

@0 = private unnamed_addr constant [2 x i8] c"\0A\00"
@i = internal global i32 zeroinitializer, align 4
@1 = private unnamed_addr constant [4 x i8] c"%d \00"

define void @main() {
entry:
  %callproc = call i32 @go(i32 10)
  store i32 %callproc, i32* @i
  %0 = load i32, i32* @i
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %0)
  %2 = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @go(i32 %a) {
entry:
  %go = alloca i32
  %a1 = alloca i32
  store i32 %a, i32* %a1
  %0 = load i32, i32* %a1
  %cmptmp = icmp eq i32 %0, 1
  br i1 %cmptmp, label %then, label %else

then:                                             ; preds = %entry
  store i32 1, i32* %go
  br label %ifcont7

else:                                             ; preds = %entry
  %1 = load i32, i32* %a1
  %cmptmp3 = icmp eq i32 %1, 2
  br i1 %cmptmp3, label %then2, label %else4

then2:                                            ; preds = %else
  store i32 1, i32* %go
  br label %ifcont

else4:                                            ; preds = %else
  %2 = load i32, i32* %a1
  %subtmp = sub i32 %2, 1
  %callproc = call i32 @go(i32 %subtmp)
  %3 = load i32, i32* %a1
  %subtmp5 = sub i32 %3, 2
  %callproc6 = call i32 @go(i32 %subtmp5)
  %addtmp = add i32 %callproc, %callproc6
  store i32 %addtmp, i32* %go
  br label %ifcont

ifcont:                                           ; preds = %else4, %then2
  br label %ifcont7

ifcont7:                                          ; preds = %ifcont, %then
  %4 = load i32, i32* %go
  ret i32 %4
}
