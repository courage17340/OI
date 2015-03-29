var
  a:array[1..30] of longint;
  n,i,j,s,x:longint;
  f:boolean;
begin
  while true do
    begin
      read(n);
      if n=0 then break;
      for i:=1 to n do read(a[i]);
      s:=0;
      for i:=1 to n do s:=s+a[i];
      if odd(s) then
        begin
          writeln('No equal partitioning.');
          continue;
        end;
      x:=s shr 1;
      s:=0;
      f:=false;
      for i:=1 to n do
        begin
          s:=s+a[i];
          if s=x then
            begin
              f:=true;
              break;
            end;
        end;
      if f then writeln('Sam stops at position ',i,' and Ella stops at position ',i+1,'.')
           else writeln('No equal partitioning.');
    end;
end.