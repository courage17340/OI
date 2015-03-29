var
  v:array[1..100] of boolean;
  a:array[1..100,1..100] of longint;
  ans,n,i,j,k,p,q,d:longint;
begin
  while not eof do begin
  readln(n);
  for i:=1 to n do
    begin
      for j:=1 to n do
        read(a[i,j]);
      readln;
    end;
  fillchar(v,sizeof(v),false);
  i:=0;j:=0;d:=maxlongint;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i,j]<d then
        begin
          d:=a[i,j];p:=i;q:=j;
        end;
  ans:=d;
  v[p]:=true;
  v[q]:=true;
  for i:=3 to n do
    begin
      p:=0;
      d:=maxlongint;
      for j:=1 to n do if not v[j] then
        for k:=1 to n do if v[k] and (a[j,k]<d) then
          begin
            d:=a[j,k];
            p:=j;
          end;
      ans:=ans+d;
      v[p]:=true;
    end;
  writeln(ans);
  end;
end.