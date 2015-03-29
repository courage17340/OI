var
  a:array[1..1100] of boolean;
  c:array[1..1100] of longint;
  b:array[1..300] of longint;
  n,i,j,k,x,y:longint;
begin
  fillchar(a,sizeof(a),true);
  i:=2;
  while i<trunc(sqrt(1100)) do
    begin
      while not a[i] do inc(i);
      for j:=2 to 1100 div i do
        a[i*j]:=false;
      inc(i);
    end;
  c[1]:=1;
  for i:=2 to 1100 do if a[i] then c[i]:=c[i-1]+1 else c[i]:=c[i-1];
  j:=0;
  for i:=1 to 1100 do
    if a[i] then
      begin
        inc(j);
        b[j]:=i;
      end;
  while not eof do
    begin
      readln(x,y);
      write(x,' ',y,':');
      k:=c[x];
      if odd(k) then y:=y*2-1 else y:=y*2;
      if y>k then for i:=1 to k do write(' ',b[i])
             else for i:=(k-y) shr 1+1 to (k-y) shr 1+y do write(' ',b[i]);
      writeln;writeln;
    end;
end.