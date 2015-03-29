var
  f:array[0..17] of qword;
  n,i:longint;k:qword;
begin
  read(n);
  f[0]:=1;k:=1;
  for i:=1 to n-1 do
    begin f[i]:=8*f[i-1]+k;k:=k*10;end;
  writeln(7*f[n-1]+k);
end.