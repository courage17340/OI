var
  n,i:longint;
  s:qword;
begin
  read(n);
  s:=1;
  for i:=1 to n do s:=int64(s*4);
  s:=int64(s div 3);
  s:=int64(s+1);
  writeln(s);
end.