var
  a:array[1..25,1..25] of longint;
  f:array[1..25,1..25,0..99] of boolean;
  i,j,n,k,max:longint;
begin
  read(n);
  for i:=1 to n do for j:=1 to i do read(a[i,j]);
  fillchar(f,sizeof(f),false);
  f[1,1,a[1,1] mod 100]:=true;
  for i:=2 to n do
    for j:=1 to i do
      for k:=0 to 99 do
        begin
          if f[i-1,j,k] then f[i,j,(k+a[i,j]) mod 100]:=true;
          if j>1 then if f[i-1,j-1,k] then f[i,j,(k+a[i,j]) mod 100]:=true;
        end;
  max:=0;
  for i:=1 to n do
    for k:=0 to 99 do
      if f[n,i,k] then if max<k then max:=k;
  writeln(max);
end.
