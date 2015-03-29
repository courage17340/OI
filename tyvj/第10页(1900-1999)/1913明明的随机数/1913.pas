var
  a:array[1..1000] of longint;
  n,i,j:longint;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do
    begin
      read(j);a[j]:=1;
    end;
  for i:=1 to 1000 do if a[i]>0 then break;
  n:=0;
  for j:=i to 1000 do inc(n,a[j]);
  writeln(n);
  for j:=i to 1000 do if a[j]>0 then write(j,' ');
  readln;readln;
end.