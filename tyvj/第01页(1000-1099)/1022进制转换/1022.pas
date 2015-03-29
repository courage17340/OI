var
  a:array[1..100] of longint;
  x,i,j:longint;
begin
  readln(x);
  fillchar(a,sizeof(a),0);
  i:=0;
  while x<>0 do
    begin
      inc(i);
      a[i]:=x mod -2;
      if a[i]=-1 then x:=(x-1) div -2 else x:=x div -2;
    end;
  for j:=i downto 1 do write(abs(a[j]));
  if i=0 then write(0);
  writeln;
end.