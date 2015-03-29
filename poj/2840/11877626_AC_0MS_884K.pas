var
  n,i:longint;
  s:string;
function f(s:string):longint;
var
  h,m:longint;
begin
  val(copy(s,1,pos(':',s)-1),h);
  delete(s,1,pos(':',s));
  val(s,m);
  if m>0 then exit(0);
  if h<=12 then exit(h+12);
  exit(h-12);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      writeln(f(s));
    end;
end.