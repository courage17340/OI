var
  a,b,d,k:longint;
  ans:int64;
function work(a,b:longint):int64;
var
  d:longint;
begin
  a:=a mod b;
  d:=b-a;
  if d=1 then exit(a);
  work:=(int64(b)*int64(work(a,d))-1) div d;
end;
begin
  readln(a,b);
  a:=a mod b;
  writeln(work(a,b));
end.