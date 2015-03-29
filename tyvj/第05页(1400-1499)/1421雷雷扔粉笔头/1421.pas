var
  a:array[0..91] of qword;
  n,i:longint;
begin
  readln(n);
  a[0]:=1;a[1]:=2;
  for i:=2 to n do a[i]:=a[i-1]+a[i-2];
  writeln(a[n]);
end.