var
  a:array[1..500,1..500] of longint;
  i,j,n,ans,t1,t2:longint;
begin
  read(n);ans:=0;
  fillchar(a,sizeof(a),0);
  for i:=1 to n-1 do
    for j:=1 to n-i do
      begin read(a[i,i+j]);a[i+j,i]:=a[i,i+j];end;
  for i:=1 to n do
    begin
      t1:=0;
      for j:=1 to n do
        if t1<a[i,j] then t1:=a[i,j];
      t2:=0;
      for j:=1 to n do
        if (t2<a[i,j])and(a[i,j]<t1) then t2:=a[i,j];
      if ans<t2 then ans:=t2;
    end;
  writeln(1);
  writeln(ans);
end.
